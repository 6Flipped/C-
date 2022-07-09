from flask_sqlalchemy import SQLAlchemy
from flask import Flask
from service.userservice import User
from service.musicserice import music

app = Flask(__name__)


app.config['SQLALCHEMY_DATABASE_URI'] ='mysql+pymysql://root:root@101.35.107.33:3306/musics'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

class Comments(db.Model):
    # 定义表名为user
    __tablename__ = 'comment'

    uid = db.Column(db.Integer)
    mid = db.Column(db.Integer)
    cscore = db.Column(db.Integer)
    comments = db.Column(db.String(1000))
    time = db.Column(db.DateTime,primary_key=True)

    def __init__(self,uid,mid,cscore,comments,time):
        self.uid=uid
        self.mid=mid
        self.cscore=cscore
        self.comments=comments
        self.time=time


def getcomment(id):
    comments = db.session.query(Comments.mid,Comments.uid,Comments.comments,Comments.cscore,User.username,User.icon).filter(Comments.uid==User.uid).filter(Comments.mid==id).all()
    return comments
#更新电影评分 从comment表中获取评分 求平均值
def updatemscore2(sid):
    musics =db.session.query(music).filter_by(mid=sid).first()
    comments =db.session.query(Comments).filter_by(mid=sid).all()
    sum = 0
    for comment in comments:
        sum += comment.cscore
    musics.mscore = sum/len(comments)
    db.session.commit()
    return musics

def getcomment_pro(uid,mid):
    comments = db.session.query(Comments).filter(Comments.uid == uid and Comments.mid == mid).first()
    return comments
