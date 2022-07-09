from flask import Flask
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.secret_key = 'xxxxxxx'

app.config['SQLALCHEMY_DATABASE_URI'] ='mysql+pymysql://root:root@101.35.107.33:3306/movies'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

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
    def __init__(self, uid, phone, username, passwd,icon,addr,sign):
        self.phone = phone
        self.username = username
        self.passwd = passwd
        self.icon = icon
        self.addr = addr
        self.sigh = sign

def getid(phone):
    user = db.session.query(User).filter_by(phone=phone)
    return user

def getusername(id):
    user = db.session.query(User).filter_by(uid=id)
    return user

def getusername(id):
    user = db.session.query(User).filter_by(uid=id)
    return user