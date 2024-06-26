<script type="text/javascript">
    //defines the location
    let x = 0;
    let y = 0;
    //defines the direction the box is moving
    let vertDir = -1;
    let horzDir = 1;
    //The function moveBox just moves the box on x,y axis by 1px.
    function moveBox() {
        //labels the box
        let box = document.getElementById('my_bouncing_box');
        //defines the boundaries
        let rightWall = window.innerWidth - 100;
        let bottomWall = window.innerHeight - 100;
        //Change direction when it hits a wall
        switch (x) {
            case rightWall:
                horzDir = -1;
                break;
            case 0:
                horzDir = 1;
                break;
        }
        switch (y) {
            case bottomWall:
                vertDir = -1;
                break;
            case 0:
                vertDir = 1;
                break;
        }
        //Change x and y
        x = x + horzDir;
        y = y + vertDir;
        //Change location of box
        box.style.left = x + 'px';
        box.style.top = y + 'px';
    }
//Run the moveBox function every x miliseconds
setInterval(moveBox, 1);
  </script>
