var canvas = document.getElementById('canvas');
var ctx = canvas.getContext('2d');
var button = document.getElementById("button");
var xcor, ycor;

var lastx = -1;
var lasty = -1;

/* start drawing lines */
ctx.beginPath();

/* keeps track of the xcor and ycor of mouse */
canvas.addEventListener("mousemove", function(evt) {
    xcor = evt.offsetX;
    ycor = evt.offsetY;
});

canvas.addEventListener('click', function(evt) {
   /* gets random hex by converting Math.random() into a hex string keeping only the values from index 2 to 7
     (via slice), convert to lowercase, and keeping only the last 6 elements of the resulting sequence */
  ctx.fillStyle = '#' + ("000000" + Math.random().toString(16).slice(2, 8).toLowerCase()).slice(-6);
  ctx.arc(xcor, ycor, 20, 0, 2 * Math.PI);
  ctx.fill();
  ctx.stroke();
  ctx.beginPath();
});


button.addEventListener("click", function(evt) {
    ctx.clearRect(0,0, canvas.width, canvas.height);
    ctx.beginPath();
    lastx = -1;
    lasty = -1;
});
