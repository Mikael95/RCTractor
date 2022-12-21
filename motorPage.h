Skip to content
Product
Solutions
Open Source
Pricing
Search
Sign in
Sign up
witnessmenow
/
simple-wifi-controlled-rc-car
Public
Code
Issues
1
Pull requests
Actions
Projects
Security
Insights
simple-wifi-controlled-rc-car/MotorWeb/motorPage.h
@witnessmenow
witnessmenow First version
Latest commit 874da60 on Dec 10, 2017
 History
 1 contributor
71 lines (69 sloc)  3.45 KB

R"(
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  </head>
  <body>
    <div class="container-fluid">
      <div class="col-xs-12"  style="height: 100vh">
        <div class="row" style="height: 33.33%; padding-top: 1em; padding-bottom:1em">
          <div class="col-xs-8" ></div>
          <div class="col-xs-4" style="text-align: center; height: 100%">
            <button id="drive" type="button" class="btn btn-default" style="height: 100%; width: 100%" onmousedown='makeAjaxCall("forward")' onmouseup='makeAjaxCall("driveStop")' ontouchstart='makeAjaxCall("forward")' ontouchend='makeAjaxCall("driveStop")'>Drive</button>
          </div>
        </div>
        <div class="row" style="height: 33.33%; padding-bottom:1em">
          <div class="col-xs-4" style="height: 100%; text-align: center">
            <button id="left" type="button" class="btn btn-default" style="height: 100%; width: 100%" onmousedown='makeAjaxCall("armUp")' onmouseup='makeAjaxCall("armStop")' ontouchstart='makeAjaxCall("armUp")' ontouchend='makeAjaxCall("armStop")'>Arm up</button>
          </div>
          <div class="col-xs-4" style="height: 100%; text-align: center">
            <button id="left" type="button" class="btn btn-default" style="height: 100%; width: 100%" onmousedown='makeAjaxCall("armDown")' onmouseup='makeAjaxCall("armStop")' ontouchstart='makeAjaxCall("armDown")' ontouchend='makeAjaxCall("armStop")'>Arm down</button>
          </div>
        </div>
        <div class="row" style="height: 33.33%; padding-bottom:1em">
          <div class="col-xs-4" style="height: 100%; text-align: center">
            <button id="left" type="button" class="btn btn-default" style="height: 100%; width: 100%" onmousedown='makeAjaxCall("left")' onmouseup='makeAjaxCall("steerStop")' ontouchstart='makeAjaxCall("left")' ontouchend='makeAjaxCall("steerStop")'>Left</button>
          </div>
          <div class="col-xs-4" style="height: 100%; text-align: center">
            <button id="right" type="button" class="btn btn-default" style="height: 100%; width: 100%" onmousedown='makeAjaxCall("right")' onmouseup='makeAjaxCall("steerStop")' ontouchstart='makeAjaxCall("right")' ontouchend='makeAjaxCall("steerStop")'>Right</button>
          </div>
          <div class="col-xs-4" ></div>
        </div>
        <div class="row" style="height: 33.33%; padding-bottom:1em">
          <div class="col-xs-8" ></div>
          <div class="col-xs-4" style="height: 100%; text-align: center">
            <button id="back" type="button" class="btn btn-default" style="height: 100%; width: 100%" onmousedown='makeAjaxCall("back")' onmouseup='makeAjaxCall("driveStop")' ontouchstart='makeAjaxCall("back")' ontouchend='makeAjaxCall("driveStop")'>Back</button>
          </div>
        </div>
      </div>
    </div>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <script> function makeAjaxCall(url){$.ajax({"url": url})}</script>
    <!--<script>
       document.addEventListener('keydown', function(event) {
          if(event.keyCode == 37) {
              //Left Arrow
              makeAjaxCall("left");            
          }
          else if(event.keyCode == 39) {
              //Right Arrow
              makeAjaxCall("right");   
          } else if(event.keyCode == 38) {
              //Up Arrow
              makeAjaxCall("forward");   
          } else if(event.keyCode == 40) {
              //Down Arrow
              makeAjaxCall("back");   
          } else if(event.keyCode == 100) {
              //?
              makeAjaxCall("armup");   
          } else if(event.keyCode == 101) {
              //?
              makeAjaxCall("armdown");   
          } else if(event.keyCode == 102) {
              //?
              makeAjaxCall("scoopdown");   
          } else if(event.keyCode == 103) {
              //?
              makeAjaxCall("scoopup");   
          } else if(event.keyCode == 104) {
              //?
              makeAjaxCall("hitchunlock");   
          } else if(event.keyCode == 105) {
              //?
              makeAjaxCall("hitchlock");   
          }
          
      });

      document.addEventListener('keyup', function(event) {
          if(event.keyCode == 37 ||event.keyCode == 39 ) {
              //Left or Right Arrow
              makeAjaxCall("steerStop");            
          }
          else if(event.keyCode == 38 ||event.keyCode == 40 ) {
              //Up or Down Arrow
              makeAjaxCall("driveStop");            
          }
          else if(event.keyCode == 101) {
              //arm stop
              makeAjaxCall("armstop");            
          }
      });
    </script>-->
  </body>
</html>

)"
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
simple-wifi-controlled-rc-car/motorPage.h at master · witnessmenow/simple-wifi-controlled-rc-car · GitHub