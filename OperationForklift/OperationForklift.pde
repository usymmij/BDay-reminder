//declare image variables
PImage img2;
PImage img;
PImage img5;
PImage img3;
PImage img4;
PImage yes;
PImage no;
PImage usernm1;
PImage usernm2;
PImage pass1;
PImage pass2;

//declare floating point variables
float userWidth;
float passWidth;

//declare strings
String DYWTATATMCTYD = "Do you want to allow this app to make changes to your device?";
String charnum = "";
String result = "";

//declare boolean variables
boolean usernameClicked = false;
boolean passwordClicked = false;
boolean YEET = false;
boolean NEET = false;
boolean tabbed = false;

//declare custom font variable
PFont myFont;

//declare integer variables
int i = 255;
int time = second();
int pickles;
int poop = 0;

void setup() {
  //print basic background
  size(680, 740);
  background(230, 230, 230);
  fill(240, 43, 130);
  rect(0, 0, 680, 740);
  fill(230, 230, 230);
  rect(2, 2, 676, 736);
  fill(118, 185, 237); 
  rect(2, 2, 676, 110);
  
  //load the images
  loadImages();
  
  //custom frame title and icon
  PImage icon = loadImage("icon.png");
  surface.setIcon(icon);
  surface.setTitle("User Account Control");
  
  //print midground
  fill(0, 0, 0);
  myFont = createFont("Segoe UI", 28);
  textFont(myFont);
  text(DYWTATATMCTYD, 40, 10, 580, 740);
  image(img, 40, 120);
  image(whichBack(), 40, 380);
}

//the images needed to load
void loadImages() {
  img = loadImage("Hehe.png");
  img2 = loadImage("UyPy.png");
  img3 = loadImage("UyPn.png");
  img4 = loadImage("UnPy.png");
  img5 = loadImage("UnPn.png");
  yes = loadImage("yes.png");
  no = loadImage("no.png");
  usernm1 = loadImage("x.png");
  usernm2 = loadImage("z.png");
  pass1 = loadImage("a.png");
  pass2 = loadImage("b.png");
}

//the main loop
void draw() {
  //println(mouseX, ",", mouseY); //used for development, shows position of mouse
  
  //print foreground
  findLength();
  time = millis();
  image(whichBack(), 40, 380);
  printBack();
  YesNo();
  textFont(myFont);
  textSize(24);
  text(result, 145, 415);
  printDots();
  //println(time);
}

//prints the dots for password section
void printDots() {
  if (charnum.length() != 0) {
    int NOfPD = 0;
    int WTF = 10;
    for (int qwerty = 1; qwerty <= charnum.length(); qwerty++) {
      fill(0);
      stroke (0);
      ellipse(150 + NOfPD, 473, WTF, WTF);
      NOfPD = NOfPD + 15;
    }
  }
}

//if the keyboard is pressed...
void keyPressed() {
  //ignore shift, control, alt, and delete keys
  if (keyCode != SHIFT && keyCode != CONTROL && keyCode != ALT && keyCode != DELETE) {
    
    if (keyCode == ENTER && result.length() != 0 && charnum.length() != 0){
      exit();
    }
    
    // if tab key is pressed.....
    else if (keyCode == TAB) {
      
      //and user is in username, switch to password
      if (usernameClicked == true) {
        usernameClicked = false;
        passwordClicked = true;
        pickles = time;
      }
      
      //if user is in password on the other hand, then go to yes
        else if (passwordClicked == true && time - pickles >= 5) {
        usernameClicked = false;
        passwordClicked = false;
        image(yes, 40, 648);
        YEET = true;
        NEET = false;
        tabbed = true;
        pickles = time;
      }
      //if in Yes go to No
       else if (YEET == true && time - pickles >= 5) {
        image(no, 347, 648);
        YEET = false;
        NEET = true;
        tabbed = true;
        pickles = time;
      }
      
      //if user isn't in anything go to username
      else if (NEET == false){
        usernameClicked = true;
      }
      
      //if backspace is pressed and user is in username, shorten username query
    } else if (keyCode == BACKSPACE && result.length() != 0 && usernameClicked == true) {
      result = result.substring(0, result.length() - 1);
      
      //if user is in username and backspace isn't pressed, add key to query
    } else if (usernameClicked == true && keyCode != BACKSPACE) {
      result = result + key;
    }
    
    //if user is in password
    if (passwordClicked == true) {
      
      //and backspace is pressed, shorten query by one
      if (keyCode == BACKSPACE && charnum.length() != 0) {
        charnum = charnum.substring(0, charnum.length() - 1);
        
        // and key pressed is not backspace add key to query
      } else if (keyCode != BACKSPACE && keyCode != TAB) {
        charnum = charnum + key;
      }
    }
  }
}

//if mouse is pressed...
void mousePressed() {
  
  if(tabbed == true){
    tabbed = false;
    YEET = false;
    NEET = false;
  }
  
  //and the mouse is on the username box, remember that
  if (mouseX >= 130 && mouseY >= 380 && mouseX <=570 && mouseY <= 430) {
    usernameClicked = true;
    passwordClicked = false;
    
    //and the mouse is on the password box, note that down
  } else if (mouseX >= 130 && mouseY >= 445 && mouseX <=570 && mouseY <= 490) {
    usernameClicked = false;
    passwordClicked = true;
    
    //and it is not on the username or password box, note that
  } else {
    usernameClicked = false;
    passwordClicked = false;
  }
  
  //and the mouse is on the yes or no button, exit the program
  if (mouseX >= 40 && mouseX <= 340 && mouseY >=645 && mouseY<=695) {
    exit();
  }
  else if (mouseX >= 345 && mouseX <= 650 && mouseY >=645 && mouseY<=695){
    exit();
  }
}

//check if the mouse is above the yes button
void Yes() {
  if (mouseX >= 40 && mouseX <= 340 && mouseY >=645 && mouseY<=695) {
    image(yes, 40, 648);
    YEET = true;
  } else {
    YEET = false;
  }
}

//check if the mouse is above the no button
void No() {
  if (mouseX >= 345 && mouseX <= 650 && mouseY >=645 && mouseY<=695) {
    image(no, 347, 648);
    NEET = true;
  } else {
    NEET = false;
  }
}

//see if the mouse is above either the yes or no button or if it had been tabbed to
void YesNo() {
  if (tabbed == false){
  Yes();
  No();
  }
  else if (tabbed == true){
    if(YEET == true){
      image(yes, 40, 648);
    }
    else if (NEET == true){
      image(no, 347, 648);
    }
  }
}

//decide which foreground to print
PImage whichBack() {
  if (result.length() != 0) {
    if (charnum.length() != 0) {
      return img2;
    } else {
      return img3;
    }
  } else {
    if (charnum.length() != 0) {
      return img4;
    } else {
      return img5;
    }
  }
}

//find how long the queries are
void findLength() {
  userWidth = textWidth(result);
  passWidth = charnum.length() * 15;
}

//print most of the foreground
void printBack()
{
  //if user is in username box..
  if (usernameClicked == true) {
    
    //and there is no text, use foreground usernm1
    if (result.length() == 0) {
      image(usernm1, 130, 380);
      
      //if there is text print usernm2
    } else if (result.length() > 0) {
      image(usernm2, 130, 380);
    }
    
    //print the input bars for username box
    stroke(i, i, i);
    rect((145 + userWidth), 390, 1, 30);
    if (poop == 0) {
      i = i + 10;
      if (i > 255) {
        poop = 1;
      }
    } else if (poop == 1) {
      i = i - 10;
      if (i < 0) {
        poop = 0;
      }
    }
    
    //print pass1 or pass2 if user is in password
  } else if (passwordClicked == true) {
    if (charnum.length() == 0) {
      image(pass2, 130, 446);
    } else if (charnum.length() > 0) { 
      image(pass1, 130, 446);
    }
    
    //print input bar for password box
    stroke(i, i, i);
    rect((145 + passWidth), 456, 1, 30);
    if (poop == 0) {
      i = i + 10;
      if (i > 255) {
        poop = 1;
      }
    } else if (poop == 1) {
      i = i - 10;
      if (i < 0) {
        poop = 0;
      }
    }
  }
}