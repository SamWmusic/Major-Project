// Make sure things are running smoothly with max
function detectMax() {
	try {
		window.max.outlet('Hello Max!');
		return true;
	} catch (e) {
		console.log('Max, where are you?');
	}
	return false;
}

// all the main code is written inside function(p) as we are running P5 in instance mode

var s = function(p) {

	var maxIsDetected = detectMax();


	// Bunch of variables for the main box
	var dimentions = innerWidth / 5;
	var moveX = 0;
	var moveY = 0;
	var currentX = innerWidth / 2;
	var currentY = innerHeight / 2;
	var returnSpeedX = 5;
	var returnSpeedY = 10;
	var rotate = 0;
	var words = 'pad';


	// Bunch of variables for the yes/no mechanichs
	var round = 0;
	var answer = 0;
	var answers = [];
	var yes = 0;
	var no = 0;
	var skip = 0;
	var left = 0;
	var right = 0;
	var counter;
	var words = 'pad';


	// Bunch of variables for the return button
	var buttdimX = innerWidth / 20;
	var buttdimY = innerHeight / 40;
	var buttX = innerWidth / 30 + buttdimX;
	var buttY = innerHeight - innerWidth / 30 - buttdimY;




	// Bunch of variables for coloures and textures
	var saturation = 0;
	var hue = 0;
	var trans = 0;
  var textcol=0;
	var img;
	var img2;


	// resise window
	p.windowResized = function() {
		p.resizeCanvas(innerWidth, innerHeight);
	}

	//load images (from github res)
	p.preload = function() {
		img = p.loadImage('https://raw.githubusercontent.com/SamWmusic/xyo/master/plexus-curve-effect-3d-blue-background_35761-250%202.jpg');
		img2 = p.loadImage('https://raw.githubusercontent.com/SamWmusic/xyo/master/smaller.png');
	}

	// setup function
	p.setup = function() {

		p.createCanvas(innerWidth, innerHeight);

		// get rid of unwanted overlay text
		if (maxIsDetected) {
			document.getElementsByTagName('body')[0].style.overflow = 'hidden';
		}

		// fill the array with 0s
		for (var i = 0; i <= 10; i++) {
			answers[i] = 0;
		}

		//set up
    p.textAlign(p.CENTER, p.CENTER);
		p.imageMode(p.CENTER);
		p.colorMode(p.HSB);
		p.rectMode(p.RADIUS);
    p.noStroke();
    p.textFont('Helvetica');

	};


// click back button
	p.mousePressed = function() {

		if (p.winMouseX < buttX + buttdimX && p.winMouseX > buttX - buttdimX &&
			p.winMouseY < buttY + buttdimY && p.winMouseY > buttY - buttdimY && round > 0) {
			answers[round] = 0;
			window.max.outlet('clear', round);
			round--
			window.max.outlet('answers', 0);
		}
	}

	p.draw = function() {

// draw background
		p.tint(50)
		p.image(img, innerWidth / 2, innerHeight / 2, innerWidth, innerHeight);





		counter++;
		if (counter > 10) {
			answer = 0;
		}


// map position of box to volumes L R
		if (moveX == 0) {
			left = 0;
			right = 0;
		}
		if (currentX > innerWidth / 2 && currentX < innerWidth * 0.65) {
			left = p.map(currentX, innerWidth / 2, innerWidth * 0.65, 0, 127);
			right = 0;
		} else if (currentX < innerWidth / 2 && currentX > innerWidth * 0.35) {
			right = p.map(currentX, innerWidth * 0.35, innerWidth / 2, 127, 0);
			left = 0;
		} else if (currentX > innerWidth * 0.65) {
			right = 0;
			left = 127;
		} else if (currentX < innerWidth * 0.35) {
			right = 127;
			left = 0;
		}


// map position of box to colour of tint
		if (currentX <= innerWidth * 0.65 &&
			currentX >= innerWidth * 0.35) {
			hue = 0;
			trans = 0;
			if (currentY < innerHeight * 0.35) {
				saturation = p.abs(p.map(currentY, innerHeight * 0.35, 0, 0, 125));
				trans = p.abs(p.map(currentY, innerHeight * 0.35, 0, 0, 1));
			} else {
				saturation = 0
			}
		} else if (currentX > innerWidth * 0.65) {
			hue = 65;
			saturation = p.abs(p.map(currentX, innerWidth * 0.65, innerWidth, 0, 225));
		} else if (currentX < innerWidth * 0.35) {
			hue = 180;
			saturation = p.abs(p.map(currentX, innerWidth * 0.35, 0, 0, 225));
		}
    if (p.winMouseX < buttX + buttdimX && p.winMouseX > buttX - buttdimX &&
			p.winMouseY < buttY + buttdimY && p.winMouseY > buttY - buttdimY && round > 0) {
			textcol=80;
		} else{
      textcol=40;
    }



    //set ammout of rotation
		rotate = p.map(moveX, 0, innerHeight / 2, 0, 0.3);


// draw main box
		p.translate(innerWidth / 2 + moveX, innerHeight / 2 + moveY);
		p.rotate(rotate);
    p.tint(hue, saturation, 225);
		p.image(img2, currentX - innerWidth / 2 - moveX, currentY - innerHeight / 2 - moveY, dimentions * 2, dimentions * 2);
		p.fill(80);
		p.textSize(innerWidth / 15);
		p.text(words, currentX - innerWidth / 2 - moveX, currentY - innerHeight / 2 - moveY);
		p.fill(80, trans);
		p.textSize(innerWidth / 25);
		p.text('skip', currentX - innerWidth / 2 - moveX, currentY - innerHeight / 2 - moveY + dimentions / 2);
		p.rotate(-rotate);
		p.translate(-innerWidth / 2 - moveX, -innerHeight / 2 - moveY);


// draw back button
		p.fill(10);
    p.rect(buttX, buttY, buttdimX, buttdimY, buttdimX/20);
    p.fill(textcol);
    p.textSize(buttdimX/3);
		p.text('back', buttX, buttY);


// move the box && bulk of logic
    currentX = moveX + innerWidth / 2;
    currentY = moveY + innerHeight / 2;
		if (p.mouseIsPressed) {
      //move box
			moveX += p.winMouseX - p.pwinMouseX;
			moveY += p.winMouseY - p.pwinMouseY;
			yes = moveX - innerWidth / 2 - dimentions;
			no = moveX + innerWidth / 2 + dimentions;
			skip = moveY + innerHeight / 2 + dimentions;
		} else {
			if (currentX != innerWidth / 2 && currentX <= innerWidth * 0.65 &&
				currentX >= innerWidth * 0.35) {
				if (currentY < innerHeight * 0.35) {
          //push box up
					skip -= (skip / returnSpeedX);
					moveY = skip - innerHeight / 2 - dimentions;
				} else if (moveY != 0) {
          // drag box back to centre
					moveY -= (moveY / returnSpeedY);
					moveX -= (moveX / returnSpeedX);
				}
				if (currentY + dimentions < 1 && !p.mouseIsPressed) {
          // if skip then reset
					moveX = 0;
					moveY = 0;
					currentX = innerWidth / 2;
					currentY = innerHeight / 2;
					right = 0;
					left = 0;
					for (var i = 0; i <= 10; i++) {
						if (round == i) {
							answers[i] = 0;
						}
					}
					window.max.outlet('answers', answers[round]);
					counter = 0;
					round++;
				}
			} else if (currentX > innerWidth * 0.65) {
        // push to  right
				yes -= (yes / returnSpeedX);
				moveX = innerWidth / 2 + dimentions + yes;
				if (currentX - dimentions > innerWidth - 1 && !p.mouseIsPressed) {
          // reset and give answer
					moveX = 0;
					moveY = 0;
					currentX = innerWidth / 2;
					currentY = innerHeight / 2;
					right = 0;
					left = 0;
					for (var i = 0; i <= 10; i++) {
						if (round == i) {
							answers[i] = 2;
						}
					}
					window.max.outlet('answers', answers[round]);
					p.image(img, innerWidth / 2, innerHeight / 2, innerWidth, innerHeight);
					counter = 0;
					round++;
				}
			} else if (currentX < innerWidth * 0.35) {
        // push to  left
				no -= (no / returnSpeedX);
				moveX = no - innerWidth / 2 - dimentions;
				if (currentX + dimentions < 1 && !p.mouseIsPressed) {
          // reset and give answer
					moveX = 0;
					moveY = 0;
					currentX = innerWidth / 2;
					currentY = innerHeight / 2;
					right = 0;
					left = 0;
					for (var i = 0; i <= 10; i++) {
						if (round == i) {
							answers[i] = 1;
						}
					}
					window.max.outlet('answers', answers[round]);
					counter = 0;
					round++;
				}
			}

		}



// display text based on round
		if (round == 0) {
			words = 'pad';
		} else if (round == 1) {
			words = 'bass';
		} else if (round == 2) {
			words = 'snare';
		} else if (round == 3) {
			words = 'kick';
		} else if (round == 4) {
			words = 'synth';
		} else if (round == 5) {
			words = 'synth';
		} else if (round == 6) {
			words = 'perc';
		} else if (round == 7) {
			words = 'pad';
		} else if (round == 8) {
			words = 'guitar';
		} else if (round == 9) {
			words = 'effects';
		} else if (round == 10) {
			words = '🎵 enjoy your track 🎵';
		}



// communicate with max
		if (maxIsDetected) {
			window.max.outlet('status', p.frameCount, p.mouseIsPressed, p.mouseX);
			window.max.outlet('position', right, left, moveX);
			window.max.outlet('round', round, answer);
		}

	};


};

// let's run the sketch in the "instance mode"
var myp5 = new p5(s);
