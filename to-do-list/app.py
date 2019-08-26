from flask import Flask, render_template, jsonify, request
from sqlite3 import connect
import json
app = Flask(__name__)

tablename="ToDoList"
col1="index"
col2="todo"

f = "data/database.db"

@app.route("/")
def root():
    db = connect(f)
    c = db.cursor()
    c.execute("CREATE TABLE IF NOT EXISTS %s ('%s' INTEGER PRIMARY KEY, '%s' TEXT)"%(tablename,col1,col2))
    db.close()
    return render_template("index.html")

@app.route("/get/", methods = ["GET"])
def get():
    db = connect(f)
    c = db.cursor()
    c.execute("SELECT * FROM %s"%(tablename))
    d = {}
    for tup in c:
        d[tup[0]] = tup[1]
    db.close()
    return jsonify(d)

@app.route("/add/", methods = ["POST"] )
def add():
    data = json.loads(request.get_data().decode('UTF-8'))
    print(data)
    db = connect(f)
    c = db.cursor()
    c.execute("INSERT INTO %s VALUES( %s, '%s' )"%(tablename, data["id"], data["text"]))
    db.commit()
    db.close()
    result = { 'result' : "success"}
    return jsonify(result = result)

@app.route("/delete/", methods = ["DELETE"])
def delete():
    data = request.data.decode('UTF-8')
    print(data)
    db = connect(f)
    c = db.cursor()
    c.execute('DELETE FROM %s WHERE "%s" = %s'%(tablename, col1, data))
    db.commit()
    db.close()
    result = { 'result' : "success"}
    return jsonify(result = result)

@app.route("/update/", methods = ["PUT"])
def update():
    data = json.loads(request.get_data().decode('UTF-8'))
    print(data)
    db = connect(f)
    c = db.cursor()
    c.execute('UPDATE %s SET %s = "%s" WHERE "%s" = %s'%(tablename, col2, data["new"], col1, data["id"]))
    db.commit()
    db.close()
    result = { 'result' : "success"}
    return jsonify(result = result)

if __name__ == "__main__":
    app.debug = True
    app.run(host='0.0.0.0')
