from flask import Flask, render_template, request, redirect, url_for, flash, session
from flask_sqlalchemy import SQLAlchemy
from service import musicserice, musiccomment, userservice,op_operation
from service.musiccomment import Comments
from service.musicserice import music
import datetime
from datetime import datetime

app = Flask(__name__)
app.secret_key = 'xxxxxxx'

app.config['SQLALCHEMY_DATABASE_URI'] ='mysql+pymysql://root:root@101.35.107.33:3306/music'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

class collection(db.Model):
    __tablename__ = 'collection'
    uid = db.Column(db.Integer,primary_key=True)
    mid=db.Column(db.Integer,primary_key=True)
    ctime=db.Column(db.DateTime)
    def __init__(self,uid,mid,ctime):
        self.uid=uid
        self.mid=mid
        self.ctime=ctime

class User(db.Model):
    # 定义表名为user
    __tablename__ = 'user'

    # 将uid设置为主键，并且默认是自增长的
    uid = db.Column(db.Integer,primary_key=True)
    # name字段，字符类型，最大的长度是50个字符
    username = db.Column(db.String(255))
    passwd = db.Column(db.String(255))
    phone = db.Column(db.String(255))
    icon = db.Column(db.String(255))
    addr = db.Column(db.String(255))
    sign = db.Column(db.String(255))
    state = db.Column(db.String(255))
    def __init__(self, phone, username, passwd,icon,addr,sign,state):
        self.phone = phone
        self.username = username
        self.passwd = passwd
        self.icon = icon
        self.addr = addr
        self.sign = sign
        self.state = state

@app.route('/')
def begin():
    return redirect('music_homepage.html')

@app.route('/enroll.html', methods=['GET', 'POST'])
def enroll():  # put application's code here
    if request.method == 'POST':
        phone = request.form.get('id')
        username = request.form.get('username')
        passwd1 = request.form.get('passwd1')
        passwd2 = request.form.get('passwd2')
        if passwd1 != passwd2 or username is None or passwd1 is None:
            return render_template('enroll.html')
        else:
            u1 = User.query.filter(User.phone == phone).first()
            if u1 is not None:
                return render_template('enroll.html')
            else:
                time = datetime.now()
                u1 = User(phone, username, passwd1, "/img/null.jpg","还没填写呢...","还没填写呢...")
                db.session.add(u1)
                db.session.commit()
                return redirect('/login.html')
    return render_template('enroll.html')

@app.route('/login.html',methods=['GET','POST'])
def login():
    if request.method == 'POST':
        phone = request.form.get('id')
        passwd1 = request.form.get('passwd1')
        u1 = User.query.filter(User.phone == phone).first()
        if u1 is None or passwd1 != u1.passwd:
            return render_template('login.html')
        else:
            session['phone'] = u1.phone
            session['username'] = u1.username
            return redirect('/music_homepage.html')
    return render_template('login.html')

#注销
@app.route('/loginout/')
def loginout():
    session.pop('username')
    return redirect('/music_homepage.html')


@app.route('/music_homepage.html',methods=['GET','POST'])
def music_homepage():
    musics = musicserice.getAllmusic()
    if request.method == 'POST':
        filmname = request.form.get('mname')
        print(filmname)
        music = musicserice.getmusicByName(filmname)
        if music ==[]:
            return render_template('music_homepage.html', **{'musics': musics},**{'search':-1})
        else:
            return render_template('music_homepage.html', **{'musics': music})
    return render_template('music_homepage.html', **{'musics': musics})

@app.route('/music_introduction.html/<id>/',methods=['GET','POST'])

def music_introduction(id):
    result = musicserice.getmusicByID(id)
    comment = musiccomment.getcomment(id)
    tmscore = musicserice.getmscore(id)
    mscore=tmscore[0]
    charmscore=str(mscore)
    #将comment的一列数据转到另外一个列表中
    comment_list = []
    for i in range(len(comment)):
        comment_list.append(str(comment[i][3]))
    #将comment_list和comment合成一个表
    comment_list_and_comment = []
    for i in range(len(comment)):
        comment_list_and_comment.append([comment[i][0],comment[i][1],comment[i][2],comment[i][3],comment[i][4],comment[i][5],comment_list[i]])
    if request.method == 'POST':
        phone= session.get('phone')
        user=User.query.filter(User.phone == phone).first()
        uid=user.uid
        mid = id
        ctime = datetime.now()
        c = collection(uid,mid,ctime)
        print('c',c)
        #查询是否已经收藏
        c1 = collection.query.filter(collection.uid == uid,collection.mid == mid).first()
        if c1 is None:
            db.session.add(c)
            db.session.commit()
        return redirect('/music_introduction.html/'+id+'/')
    return render_template('music_introduction.html', **{'music': result[0]},**{'comment_list_and_comment':comment_list_and_comment},**{'mscore':mscore},**{'charmscore':charmscore})

# ————————————这个要修改上面的那个实现禁言功能——————
@app.route('/music_discuss.html/<id>/',methods=['POST','GET'])
def music_discuss(id):
    if session.get('username') == None:
        return redirect('/login.html')
    music = musicserice.getmusicByID(id)
    phone = session.get('phone')
    if request.method == 'POST':
        user_s = User.query.filter_by(phone=phone).first()
        print(user_s.state)
        print(user_s.uid)
        if user_s.state == '1':#代表被禁言
            return render_template('music_discuss.html', **{'music': music[0]})
        else:
            comment = request.form.get('comment')
            print(comment)
            user = userservice.getid(phone)
            user_id = user[0].uid
            music_id = id
            time = datetime.now()
            comment = musiccomment.Comments(user_id,music_id,8,comment,time)
            db.session.add(comment)
            db.session.commit()
            result = musicserice.getmusicByID(id)
            comments = musiccomment.getcomment(id)
            return render_template('music_introduction.html', **{'music': result[0]}, **{'comments': comments})
    else:
        return render_template('music_discuss.html', **{'music': music[0]})



@app.route('/music_type.html/<type>/<flag>',methods=['GET','POST'])
def musics_type(type,flag):
    if flag == '1':
        if type == 'all':
            musics1 = musicserice.getAllmusic()
            print(musics1[0].mname)
            return render_template('music_type.html', **{'musics': musics1})
        else:
            musics2 = musicserice.getmusicBytype(type)
            print(musics2[0].mname)
            return render_template('music_type.html', **{'musics': musics2})
    elif flag == '2':
        if type == 'all':
            musics1 = musicserice.getAllmusic()
            return render_template('music_type.html', **{'musics': musics1})
        else:
            musics2 = musicserice.getmusicBySinger(type)
            return render_template('music_type.html', **{'musics': musics2})
    elif flag == '3':
        if type == 'all':
            musics1 = musicserice.getAllmusic()
            return render_template('music_type.html', **{'musics': musics1})
        else:
            musics2 = musicserice.getmusicByLanguage(type)
            return render_template('music_type.html', **{'musics': musics2})
    elif flag == '4':
        if type == 'all':
            musics1 = musicserice.getAllmusic()
            return render_template('music_type.html', **{'musics': musics1})
        else:
            musics2 = musicserice.getmusicByTime(type)
            return render_template('music_type.html', **{'musics': musics2})
    else:
        return render_template('music_type.html')

#以下个人信息相关
@app.route('/music_user.html')
def music_user():
    return render_template('music_user.html')

@app.route('/user_xx.html',methods=['GET','POST'])
def user_xx():
    u1 = User.query.filter(User.phone == session['phone']).first()
    session['addr'] = u1.addr
    session['icon'] = u1.icon
    session['sign'] = u1.sign
    session['passwd'] = u1.passwd
    session['username'] = u1.username
    return render_template('user_xx.html')

@app.route('/user_sc.html',methods=['GET','POST'])
def user_sc():
    u1 = User.query.filter(User.phone == session['phone']).first()
    data=db.session.query(music.mname, collection.ctime,collection.mid).filter(collection.uid == u1.uid).filter(music.mid == collection.mid).all()
    return render_template('user_sc.html',**{'data':data})


@app.route('/user_xiaoxi.html')
def user_xiaoxi():
    return render_template('user_xiaoxi.html')

@app.route('/user_pl.html')
def user_pl():
    u1 = User.query.filter(User.phone == session['phone']).first()
    data = db.session.query(Comments.comments,Comments.cscore,Comments.time,music.mname).filter(Comments.uid == u1.uid).filter(Comments.mid == music.mid).all()
    return render_template('user_pl.html',**{'data':data})

#用户信息修改
@app.route('/user_xx_update.html',methods=['GET','POST'])
def user_xx_update():
    if request.method == 'POST':
        addr = request.form.get('addr')
        username1=request.form.get('username1')
        sign = request.form.get('sign')
        passwd = request.form.get('passwd')

        phone = session.get('phone')
        user = userservice.getid(phone)
        user_id = user[0].uid
        user = User.query.filter(User.uid == user_id).first()
        user.addr = addr
        user.sign = sign
        user.username =username1
        user.passwd = passwd

        db.session.commit()
        return redirect('/user_xx.html')
    #收藏内容保存到数据库

#用户收藏音乐
@app.route('/sc_update.html',methods=['GET','POST'])
def sc():
    print('sc')
    if request.method == 'POST':
        tmid = request.form.get('mid')
        phone = session.get('phone')
        user = userservice.getid(phone)
        user_id = user[0].uid
        music = musicserice.getmusicByID(tmid)
        music_id = music[0].mid
        time = datetime.now()
        collection = Collection.query.filter(Collection.uid == user_id).filter(Collection.mid == music_id).first()
        if collection:
            return '已收藏'
        else:
            collection = Collection(user_id,music_id,time)
            db.session.add(collection)
            db.session.commit()
            return '收藏成功'
    else:
        return '请求方式错误'


#删除收藏
@app.route('/user_sc_update.html',methods=['GET','POST'])
def user_sc_update():
    if request.method == 'POST':
        phone = session.get('phone')
        user = userservice.getid(phone)
        user_id = user[0].uid
        tmid=request.form.get('mid')
        collections = collection.query.filter(collection.uid == user_id).filter(collection.mid == tmid).first()
        db.session.delete(collections)
        db.session.commit()
        return redirect('/user_sc.html')














#以下为管理员相关
@app.route('/op_Homepage.html')
#跳转测试入口
def op_signup():
    return redirect('/op_login.html')

@app.route('/op_Homepage.html',methods = ['GET','POST'])
def op_registed(): #注册
    if request.method == 'POST':
        opid = request.form.get('opid')
        mname = request.form.get('mname')
        #print(mname)
        password1 = request.form.get('op_password1')
        password2 = request.form.get('op_password2')
        #没判空
        if password1 != password2:
            return redirect('/op_Homepage.html')
        else:
            opid_test = op_operation.manager.query.filter(op_operation.manager.opid == opid).first()
            opname = op_operation.manager.query.filter(op_operation.manager.mname == mname).first()
            #print(opname)
            if opname is None or opid_test is None:#不重复
                op1 = op_operation.manager(opid,password2,mname,'/')
                db.session.add(op1)
                db.session.commit()
                return redirect('/op_login.html')
            else:
                return redirect('/op_Homepage.html')

@app.route('/op_login.html',methods=['GET','POST'])
def op_login():
    if request.method == 'POST':
        opid = request.form.get('opid')
        password = request.form.get('op_password')
        if opid is not None and password is not None:
            opname = op_operation.manager.query.filter(op_operation.manager.opid == opid).first()
            if opname is not None:
                op_pwd = op_operation.manager.query.filter(op_operation.manager.passwd == password).first()
                if op_pwd is None:
                    #密码不对
                    return render_template('op_login.html')
                else:
                    session['opid'] = opid
                    opInfo = op_operation.getOpInfo(opid)
                    return render_template('op_info.html', **{'op_infos': opInfo} )
            else:
                return render_template('op_login.html')
        else:
            return render_template('op_login.html')
    else:
        return render_template('op_login.html')

@app.route('/op_info.html')
def op_info():
    opid = session['opid']
    opInfo = op_operation.getOpInfo(opid)
    return render_template('op_info.html',**{'op_infos': opInfo})

@app.route('/op_Ban.html')
def ban():
    users = userservice.getAlluser()
    return render_template('op_Ban.html', **{'users': users})

@app.route('/op_Ban.html/<id>')
def ban_id(id):#1禁言 0/NULL非禁言
    user = userservice.User.query.filter(userservice.User.uid == id).first()
    if user is None:#查无此人？？？
        print(user)
        print('1')
        return redirect('/op_Ban.html')
    else:
        if user.state == "" or user.state == '0':
            #未禁言则禁言
            print(user.state)
            print('2')
            User.query.filter_by(uid=id).update({'state': '1'})
        else:
            #已经禁言则解禁
            print(user.state)
            print('3')
            User.query.filter_by(uid=id).update({'state': '0'})
        db.session.commit()
        return redirect('/op_Ban.html')

@app.route('/op_Examine.html')
def op_Examine():
    musics = musicserice.getAllmusic()
    return render_template('op_Examine.html', **{'musics': musics})

@app.route('/op_Examine.html/<mid>')
def op_ExamineByMid(mid):
    music = musicserice.getmusicByID(mid)
    comment = musiccomment.getcomment(mid)
    return render_template('op_AdjustMusic.html', **{'music': music}, **{'comments': comment})

@app.route('/op_AdjustMusic.html/<uid>/<mid>')#删除评论
def op_deleteComment(uid, mid):
    from service.musiccomment import db     #YES!
    comment_delete = musiccomment.getcomment_pro(uid, mid)
    print('666')
    if comment_delete is None:
        #评论查找失败？？？
        music = musicserice.getmusicByID(mid)
        comment = musiccomment.getcomment(mid)
        return render_template('op_AdjustMusic.html', **{'music': music}, **{'comments': comment})
    else:
        db.session.delete(comment_delete)
        db.session.commit()
        music = musicserice.getmusicByID(mid)
        comment = musiccomment.getcomment(mid)
        return render_template('op_AdjustMusic.html', **{'music': music}, **{'comments': comment})

@app.route('/op_Edit.html')#编辑音乐信息
def op_Edit():
    musics = musicserice.getAllmusic()
    return render_template('op_Edit.html', **{'musics': musics})

@app.route('/op_Edit.html/<mid>')
def op_EditByMid(mid):
    music = musicserice.getmusicByID(mid)
    comment = musiccomment.getcomment(mid)
    return render_template('op_AdjustMusic.html', **{'music': music}, **{'comments': comment})

@app.route('/op_Edit.html/<mid>/<edittype>', methods=['GET','POST'])
def op_EditByMid_Pro(mid,edittype):
    if request.method == 'POST':
        music = musicserice.getmusicByID(mid)
        if music is None:
            return redirect('/op_Examine.html')
        else:
            if edittype =='1':
                #修改海报coding
                music = musicserice.getmusicByID(mid)
                comment = musiccomment.getcomment(mid)
                return render_template('op_AdjustMusic.html', **{'music': music}, **{'comments': comment})
            elif edittype == '2':
                #修改歌名
                mname = request.form.get('mname')
                print(mname)
                db.session.query(musicserice.music).filter(musicserice.music.mid == mid).update({musicserice.music.mname: mname})
                db.session.commit()
                music = musicserice.getmusicByID(mid)
                comment = musiccomment.getcomment(mid)
                return render_template('op_AdjustMusic.html', **{'music': music}, **{'comments': comment})
            elif edittype == '3':
                #修改歌手
                singer = request.form.get('singer')
                print(singer)
                db.session.query(musicserice.music).filter(musicserice.music.mid == mid).update({musicserice.music.singer: singer})
                db.session.commit()
                music = musicserice.getmusicByID(mid)
                comment = musiccomment.getcomment(mid)
                return render_template('op_AdjustMusic.html', **{'music': music}, **{'comments': comment})
            elif edittype == '4':
                #修改音乐类型
                type = request.form.get('type')
                print(type)
                db.session.query(musicserice.music).filter(musicserice.music.mid == mid).update({musicserice.music.type: type})
                db.session.commit()
                music = musicserice.getmusicByID(mid)
                comment = musiccomment.getcomment(mid)
                return render_template('op_AdjustMusic.html', **{'music': music}, **{'comments': comment})
            elif edittype == '5':
                #修改音乐语言
                language = request.form.get('language')
                print(language)
                db.session.query(musicserice.music).filter(musicserice.music.mid == mid).update({musicserice.music.language: language})
                db.session.commit()
                music = musicserice.getmusicByID(mid)
                comment = musiccomment.getcomment(mid)
                return render_template('op_AdjustMusic.html', **{'music': music}, **{'comments': comment})
            elif edittype == '6':
                #修改音乐发行时间
                createtime = request.form.get('createtime')
                print(createtime)
                db.session.query(musicserice.music).filter(musicserice.music.mid == mid).update({musicserice.music.createtime: createtime})
                db.session.commit()
                music = musicserice.getmusicByID(mid)
                comment = musiccomment.getcomment(mid)
                return render_template('op_AdjustMusic.html', **{'music': music}, **{'comments': comment})
    else:
        music = musicserice.getmusicByID(mid)
        comment = musiccomment.getcomment(mid)
        return render_template('op_AdjustMusic.html', **{'music': music}, **{'comments': comment})

if __name__ == '__main__':
    db.create_all()
    app.run(debug=True)