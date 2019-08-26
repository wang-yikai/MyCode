var x_tag = '<span class="glyphicon glyphicon-remove pull-right"></span>';
var edit_tag = '<span class="glyphicon glyphicon-pencil pull-right" style="padding-right: 20px;"></span>';
var submit = '<button class="btn btn-info">Edit</button>'
var orig_text = ""; //original text before edits
var to_do = {}; //fetches to do list
var counter = 1; //for id

var remove_li = function() {
  $.ajax({
     type : "DELETE",
     url : "/delete/",
     async: false,
     data: this.parentNode.id, //data has to be a string
     datatype: "charset=utf-8",
     contentType: "text/plain",
     success: function(result) {
         console.log(result);
     }
  });
  this.parentNode.parentNode.removeChild(this.parentNode);
};

var submit_edits = function() {
    var obj = { "id": this.parentNode.id, "new": this.parentNode.children[0].value };
    $.ajax({
       type : "PUT",
       url : "/update/",
       async: false,
       data: JSON.stringify(obj), //data has to be a string
       success: function(result) {
           console.log(result);
       }
    });

    var newItem = document.createElement("li");
    newItem.classList.add("list-group-item");
    newItem.id = this.parentNode.id;

    newItem.innerHTML = this.parentNode.children[0].value;
    newItem.innerHTML += (x_tag + edit_tag);
    //adds event listener to the "X" button
    newItem.children[0].addEventListener('click', remove_li);
    newItem.children[1].addEventListener('click', edit_li);

    document.getElementById("toDoUL").replaceChild(newItem, this.parentNode);
};

var edit_li = function() {
  orig_text = this.parentNode.innerHTML.substring(0,this.parentNode.innerHTML.length - (x_tag.length + edit_tag.length));

  var li_new = document.createElement("li");
  li_new.classList.add("list-group-item");
  li_new.id = this.parentNode.id;

  var new_input = '<input type="text" class="form-control" placeholder="';
  new_input += orig_text + '">';

  li_new.innerHTML = new_input + submit;
  li_new.children[1].addEventListener("click", submit_edits);

  document.getElementById("toDoUL").replaceChild(li_new, this.parentNode);
};

var addToDo = function() {
  var userInput = document.getElementById("input");

  if(userInput.value.length != 0){
      var newItem = document.createElement("li");
      var obj = { "id": counter.toString(), "text": userInput.value };
      console.log(obj);

      $.ajax({
         type : "POST",
         url : "/add/",
         async: false,
         data: JSON.stringify(obj),
         success: function(result) {
             console.log(result);
         }
      });

      newItem.classList.add("list-group-item");
      newItem.id = counter.toString();
      counter++;

      newItem.innerHTML = userInput.value;
      newItem.innerHTML += (x_tag + edit_tag);

      //adds event listener to the "X" button
      newItem.children[0].addEventListener('click', remove_li);
      //adds event listener to the edit button
      newItem.children[1].addEventListener('click', edit_li);

      document.getElementById("toDoUL").appendChild(newItem);

    clearInput(userInput);
  } else{
      alert("Invalid response: Field cannot be blank!");
  }
};

var get_data = function() {
  $.ajax({
     type : "GET",
     url : "/get/",
     async: false,
     datatype: "json",
     success: function(result) {
          to_do = result;
          console.log(result);
     }
  });

  keys = Object.keys(to_do);
  for(var i = 0; i < keys.length; ++i) {
    if (keys[i] >= counter) {
      counter = parseInt(keys[i]) + 1;
    }
    var newItem = document.createElement("li");
    newItem.classList.add("list-group-item");
    newItem.id = keys[i].toString();

    newItem.innerHTML = to_do[keys[i]];
    newItem.innerHTML += (x_tag + edit_tag);

    //adds event listener to the "X" button
    newItem.children[0].addEventListener('click', remove_li);
    //adds event listener to the edit button
    newItem.children[1].addEventListener('click', edit_li);

    document.getElementById("toDoUL").appendChild(newItem);
  }

  to_do = {};

};

var clearInput = function(currInput) {
  currInput.value = null;
};
