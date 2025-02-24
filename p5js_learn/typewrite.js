let points;
let font;
let colorOffset = 0; 
let flowerPoint = [];
let baseHue;
let seed=0;
let branches = [];
let growing = false;
let growthProgress = 0;

class Flower {
  constructor(x, y) {
    this.x = x;
    this.y = y;
    this.petalLength = random(45, 60);
    this.angles = [0, 72, 144, 216, 288];
    this.lengthVariations = this.angles.map(() => random(0.6, 1.2));
    this.hueOffset = random(-20, 20);
  }
  
  display() {
    push();
    translate(this.x, this.y);
    let noiseVal = noise(seed);
    
    let flowerHue = (baseHue + this.hueOffset) % 360;
    colorMode(HSB);
    
    for(let i = 0; i < 5; i++) {
      push();
      // 旋转到对应角度
      let angle = this.angles[i]+map(noiseVal, 0, 1, -45, 45);
      rotate(angle);
      
      let gradient = drawingContext.createLinearGradient(
        0, 0,
        0, -this.petalLength * this.lengthVariations[i]
      );
      
      gradient.addColorStop(0, `hsla(${flowerHue}, 80%, 50%, 0.8)`);
      gradient.addColorStop(0.5, `hsla(${(flowerHue + 15) % 360}, 80%, 60%, 0.6)`);
      gradient.addColorStop(1, `hsla(${(flowerHue + 30) % 360}, 80%, 70%, 0.3)`);
      
      drawingContext.fillStyle = gradient;
      noStroke();
      // 绘制花瓣
      beginShape();
      vertex(0, 0);
      bezierVertex(
        5, -this.petalLength * this.lengthVariations[i] * 0.4,
        5, -this.petalLength * this.lengthVariations[i] * 0.6,
        0, -this.petalLength * this.lengthVariations[i]
      );
      bezierVertex(
        -5, -this.petalLength * this.lengthVariations[i] * 0.6,
        -5, -this.petalLength * this.lengthVariations[i] * 0.4,
        0, 0
      );
      endShape(CLOSE);
      pop();
    }
    
    fill((flowerHue + 15) % 360, 80, 90);
    ellipse(0, 0, 5, 5);
    
    pop();
  }
}

class Branch {
  constructor(startX, startY, level = 1) {
    this.startX = startX;
    this.startY = startY;
    this.level = level; 
    this.length = this.level === 1 ? random(20, 30) : random(10, 20);
    this.angle = random(360);
    this.progress = 0;
    this.thickness = this.level === 1 ? random(1.5, 2.5) : random(0.5, 1);
    this.growSpeed = random(0.02, 0.05);
    
    this.controlX = this.startX + cos(this.angle + random(-30, 30)) * this.length * 0.5;
    this.controlY = this.startY + sin(this.angle + random(-30, 30)) * this.length * 0.5;
    
    this.endX = this.startX + cos(this.angle) * this.length;
    this.endY = this.startY + sin(this.angle) * this.length;

    this.subBranches = [];
    if (this.level === 1) {
      this.willCreateSubBranches = true;
    } else {
      this.willCreateSubBranches = false;
    }
  }

  grow() {
    if (this.progress < 1) {
      this.progress += this.growSpeed;
      if (this.progress >= 1 && this.willCreateSubBranches) {
        this.createSubBranches();
      }
    }
    
    for (let subBranch of this.subBranches) {
      subBranch.grow();
    }
    
    return this.progress >= 1;
  }

  createSubBranches() {
    if (this.level === 1) {
      let numBranches = floor(random(2, 4));
      for (let i = 0; i < numBranches; i++) {
        this.subBranches.push(new Branch(this.endX, this.endY, 2));
      }
      this.willCreateSubBranches = false;
    }
  }

  display() {
    let currentEndX = lerp(this.startX, this.endX, this.progress);
    let currentEndY = lerp(this.startY, this.endY, this.progress);
    let currentControlX = lerp(this.startX, this.controlX, this.progress);
    let currentControlY = lerp(this.startY, this.controlY, this.progress);
    
    let startColor, endColor;
    if (this.level === 1) {
      startColor = 'hsla(30, 70%, 35%, 0.8)';
      endColor = 'hsla(30, 60%, 45%, 0.6)';
    } else {
      startColor = 'hsla(120, 70%, 35%, 0.8)';
      endColor = 'hsla(120, 60.00%, 45.10%, 0.63)';
    }
    
    let gradient = drawingContext.createLinearGradient(
      this.startX, this.startY, currentEndX, currentEndY
    );
    gradient.addColorStop(0, startColor);
    gradient.addColorStop(1, endColor);
    
    drawingContext.strokeStyle = gradient;
    drawingContext.lineWidth = this.thickness;
    
    drawingContext.beginPath();
    drawingContext.moveTo(this.startX, this.startY);
    drawingContext.quadraticCurveTo(
      currentControlX, currentControlY,
      currentEndX, currentEndY
    );
    drawingContext.stroke();
    
    for (let subBranch of this.subBranches) {
      subBranch.display();
    }
  }
}

function preload() {
  font = loadFont('assets/RusticRoadway.otf'); // you could use another font if you want
}

function setup() {
  createCanvas(600, 600);         //comment out if using SVG
  background(0);
  angleMode(DEGREES);
  baseHue = random(360); 
  points = getPoints('A');
  flowerPoint = new Array(Math.floor(points.length/15));
  regenerateFlowers();
  initBranches();
}

function draw() {
    background(255);

    translate(width/2-180, height/2+100);

    drawTypeface()

    colorOffset = (colorOffset + 1) % 360;
    seed+=0.01;
}

function drawTypeface(){
  noStroke();
  //draw the points
  for (let i = 0; i < points.length; i++) {
    colorMode(HSB);
    fill(baseHue, 80, 80);
    ellipse(points[i].x, points[i].y, 4, 4);
  }
  //draw the branches
  if (growing) {
    let allGrown = true;
    branches.forEach(branch => {
      branch.display();
      if (!branch.grow()) {
        allGrown = false;
      }
    });
    if (allGrown) {
      growing = false;
    }
  } else {
    branches.forEach(branch => branch.display());
  }
  //draw the flowers
  for(let i = 0; i < flowerPoint.length; i++) {
    if(flowerPoint[i]) {
      flowerPoint[i].display();
    }
  }
}

function regenerateFlowers() {
  let selectedPoints = [];
  let numPoints = Math.floor(points.length/15);
  let indices = Array.from({length: points.length}, (_, i) => i);
  
  for(let i = indices.length - 1; i > 0; i--) {
      const j = Math.floor(random(i + 1));
      [indices[i], indices[j]] = [indices[j], indices[i]];
  }
  
  for(let i = 0; i < numPoints; i++) {
      selectedPoints.push(points[indices[i]]);
      flowerPoint[i] = new Flower(selectedPoints[i].x, selectedPoints[i].y);
  }
}

function initBranches() {
  branches = [];
  growing = true;
  growthProgress = 0;
  
  //generate branches
  points.forEach(point => {
    let branchCount = floor(random(2, 4));
    for (let i = 0; i < branchCount; i++) {
      branches.push(new Branch(point.x, point.y));
    }
  });
}

function keyPressed(){
  points = getPoints(String.fromCharCode(keyCode));
  baseHue = random(360);
  regenerateFlowers();
  initBranches(); 
}

// function that gets the points of each letter
function getPoints(word){
  return font.textToPoints(word, 0, 0, 300, { // location and size of letter
    sampleFactor: .1, //how many points (increase number to see more points)
    simplifyThreshold: 0
  });
}