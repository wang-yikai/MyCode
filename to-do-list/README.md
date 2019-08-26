# project1-yw3193-vl1042-cc5721-ig907-sjg548
# Website:
http://ec2-18-220-171-148.us-east-2.compute.amazonaws.com/

A website that keeps track of your tasks and allows you to update them!  

# Team Humble Donuts
### Yikai Wang - yw3193  
### Charles Chan - cc5721  
### Isaiah Garnett - ig907  
### Vincent Liok - vl1042  
# How To Run:  
### Requires:
* Python (Flask, json, sqlite3)
* sqlite3

### To Start:
In your command console, type:  
```  
python app.py  
```  

If you can't connect to the host when running application, change:  
```python  
app.run(host='0.0.0.0')
```  
to:  
```python  
app.run()
```  

### To Reset Database:    
```  
cd /data  
sudo rm database.db  
sqlite3 database.db  
CREATE TABLE ToDoList ('index' INTEGER PRIMARY KEY, 'todo' TEXT);
```  

# Project Map:
```  
app.py      - main application, handles routes  
README.md   - you are reading it  
.gitignore  - ignores certain files when pushing  
data/  
    database.db - contains to-do list tasks  

static/  - contains bootstrap, jquery, and custom css and js  
    css/  - contains css  

        bootstrap.min.css  - bootstrap css  
        overwrite.css   - overwrites bootstrap  

    fonts/  - contains fonts used for buttons  

        glyphicons-halflings-regular.eot  - font file  
        glyphicons-halflings-regular.svg  - font file  
        glyphicons-halflings-regular.ttf  - font file  
        glyphicons-halflings-regular.woff - font file  
        glyphicons-halflings-regular.woff2  - font file  

    js/   - contains javascript  

        addbutton.js  - gives ajax requests to backend via route. Handles list elements  
        jquery-3.3.1.min.js   - enables ajax calls  

templates/  - contains html file  
    index.html  - to-do list page  

server files/   - contains files and code used to deploy application  
    AdditionalFiles.txt   - code for systemd Unit File and server block configuration file  
    project.ini   - uWSGI Configuration File  
    wsgi.py  - WSGI Entry Point  
```
