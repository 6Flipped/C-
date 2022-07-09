from flask import Flask, render_template, request, redirect, url_for, flash, session
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.secret_key = 'xxxxxxx'

app.config['SQLALCHEMY_DATABASE_URI'] ='mysql+pymysql://root:root@101.35.107.33:3306/music'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

if db != None:
    db.create_all()
    app.run(debug=True)