var canvas = document.getElementById('canvas');
var ctx = canvas.getContext('2d');
var button = document.getElementById("button");
var xcor, ycor;

var rid = 0;

/* start drawing */
ctx.beginPath();


var stopIt = function() {
    window.cancelAnimationFrame( rid );
};

/* closure structure */
var animate = function(evt) {
  var x = 40;
  stopIt();

  var drawCircle = function(evt) {
    ctx.clearRect(0,0, canvas.width, canvas.height);

     /* gets random hex by converting Math.random() into a hex string keeping only the values from index 2 to 7
       (via slice), convert to lowercase, and keeping only the last 6 elements of the resulting sequence */
    ctx.fillStyle = '#' + ("000000" + Math.random().toString(16).slice(2, 8).toLowerCase()).slice(-6);
    ctx.arc(x, canvas.height/2, 20, 0, 2 * Math.PI);
    ctx.fill();
    ctx.stroke();
    ctx.beginPath();
    x++;
    rid = window.requestAnimationFrame( drawCircle );
  };

  drawCircle();
};

// /* keeps track of the xcor and ycor of mouse */
// canvas.addEventListener("mousemove", function(evt) {
//     xcor = evt.offsetX;
//     ycor = evt.offsetY;
// });

canvas.addEventListener('click', animate );


button.addEventListener("click", function(evt) {
    stopIt();
    ctx.beginPath();
});
