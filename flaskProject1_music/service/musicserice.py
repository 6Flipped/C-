from flask_sqlalchemy import SQLAlchemy
from flask import Flask
from sqlalchemy import Column, Integer, String, extract

app = Flask(__name__)


app.config['SQLALCHEMY_DATABASE_URI'] ='mysql+pymysql://root:root@101.35.107.33:3306/musics'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)
class music(db.Model):
    __tablename__ = 'music'
    mid = Column(Integer, primary_key=True)
    poster = Column(String(255))
    mname = Column(String(255))
    singer = Column(String(255))
    type = Column(String(255))
    language = Column(String(255))
    company = Column(String(255))
    createtime = Column(String(255))
    word = Column(String(255))
    mscore = Column(Integer)


#获取全部电影
def getAllmusic():
    musics =db.session.query(music).order_by(music.mid)
    return musics

def getmusicBymusictype(type):
    musics =db.session.query(music).filter_by(type=type)
    return musics

#获取评分前10的电影
def getTop10music():
    musics =db.session.query(music).order_by(-music.score).limit(10)
    return musics

#获取评分前10的电影，根据电影类型,参数类型名称
def getTop10musicBytype(stype):
    musics =db.session.query(music).order_by(-music.score).filter_by(type=stype).limit(10)
    return musics

#获取类型的全部电影,参数类型名称
def getmusicBytype(stype):
    musics =db.session.query(music).filter(music.type.like('%'+stype+'%')).all()
    return musics

#根据ID获取电影详情
def getmusicByID(sid):
    musics =db.session.query(music).filter_by(mid=sid)
    return musics
#根据ID获取电影详情
def getmusicbyid(sid):
    musics =db.session.query(music.mid,music.poster,music.mname,music.language,music.singer,music.createtime,music.type).filter_by(mid=sid).first()
    return musics

def getmusicBySinger(sid):
    musics =db.session.query(music).filter_by(singer=sid)
    return musics

def getmusicByLanguage(sid):
    musics =db.session.query(music).filter_by(language=sid)
    return musics

#根据名字获取电影详情
def getmusicByName(sid):
    musics =db.session.query(music).filter(music.mname.like('%'+sid+'%')).all()
    return musics

def getmusicByTime(Time):
    if Time == '90年代':
        musics = db.session.query(music).filter(music.createtime.between('1990-01-01','1999-01-01')).all()
    elif Time == '更早':
        musics = db.session.query(music).filter(extract('year', music.createtime) <= 1989).all()
    elif Time == '10年代':
        musics = db.session.query(music).filter(music.createtime.between('2010-01-01', '2020-01-01')).all()
    elif Time == '00年代':
        musics = db.session.query(music).filter(music.createtime.between('2000-01-01', '2010-01-01')).all()
    else:
        musics = db.session.query(music).filter(extract('year',music.createtime) == Time).all()
    return musics


#g根据id反回电影平分
def getmscore(sid):
    musics =db.session.query(music.mscore,music.mname).filter_by(mid=sid).first()
    return musics
