//clock

// 12-hour colors
const colors = [
  [255, 107, 107],   // 珊瑚红
  [255, 159, 28],    // 橙黄
  [255, 191, 105],   // 杏黄
  [186, 220, 88],    // 嫩绿
  [51, 217, 178],    // 青碧
  [84, 160, 255],    // 天蓝
  [72, 52, 212],     // 靛青
  [162, 155, 254],   // 淡紫
  [255, 107, 129],   // 粉红
  [225, 95, 219],    // 玫紫
  [204, 169, 133],   // 杏褐
  [131, 149, 167],   // 青灰
  [255, 87, 34],     // 深橙
  [0, 150, 136]      // 蓝绿
];

const texts=[
  "Have a good day!",
  "“It always seems impossible until it’s done.”\n— Nelson Mandela",
  "“Happiness is not something ready-made. It comes from your own actions.”\n — Dalai Lama",
  "“Tomorrow is now.”\n — Eleanor Roosevelt",
  "“Everything you can imagine is real.”\n — Pablo Picasso",
  "“Never let your emotions overpower your intelligence.”\n — Drake",
  "“Live in the sunshine, swim the sea, drink the wild air.”\n — Ralph Waldo Emerson",
  "“It is never too late to be what you might have been.”\n — George Eliot",
  "“Live a simple life; you will own the most beautiful treasures of the world!”\n — Mehmet Murat Ildan",
  "“Happiness consists not in having much, but in being content with little.”\n — Marguerite Gardiner"
];

let fireworks = []; 
const PARTICLE_COUNT = 40; 

let stars = []; 
const STAR_COUNT = 100;
let clouds = []; 
const CLOUD_COUNT = 8;

let currentText;

let areaW=740;
let areaH=600;
let rectW=areaW/60;
let rectH=areaH/12;


class Particle {
  constructor(x, y, col) {
    this.pos = createVector(x, y);
    this.vel = p5.Vector.random2D().mult(random(2, 8));
    this.acc = createVector(0, 0.2);
    this.lifespan = 255;
    this.color = col;
  }

  update() {
    this.vel.add(this.acc);
    this.pos.add(this.vel);
    this.lifespan -= 6;
  }

  display() {
    noStroke();
    fill(this.color[0], this.color[1], this.color[2], this.lifespan);
    ellipse(this.pos.x, this.pos.y, 4, 4);
  }

  isDead() {
    return this.lifespan <= 0;
  }
}

function setup() {
  createCanvas(800, 600);
  angleMode(DEGREES); 
  shuffleArray(colors);
  textAlign(CENTER, CENTER); 
  textSize(20); 
  currentText = random(texts);

  for (let i = 0; i < STAR_COUNT; i++) {
    stars.push({
      x: random(width),
      y: random(height),
      size: random(1, 3),
      twinkle: random(0, 255)
    });
  }
  
  for (let i = 0; i < CLOUD_COUNT; i++) {
    clouds.push({
      x: random(width),
      y: random(height),
      size: random(30, 80),
      speed: random(0.2, 0.5)
    });
  }
}

function draw() { 
  let hr = hour(); 
  let mn = minute();
  let sc = second();

  if (hr > 6 && hr <= 18) {
    background(135, 206, 235); 
    
    let sunY = map(hr, 6, 18, height-50, 50);
    fill(255, 200, 64);
    noStroke();
    circle(100, sunY, 60);
    
    fill(255, 255, 255, 200);
    noStroke();
    for (let cloud of clouds) {
      drawCloud(cloud.x, cloud.y, cloud.size);
      cloud.x += cloud.speed;
      if (cloud.x > width + 100) cloud.x = -100;
    }

    fill(255, 255, 255, 255); 
    textStyle(BOLD);
    text(currentText, width/2, height/4);

  } else {
    background(10, 10, 35); 
    
    fill(255, 255, 200);
    noStroke();
    circle(100, 100, 50);
    fill(10, 10, 35);
    circle(85, 85, 50);
    
    for (let star of stars) {
      star.twinkle = sin(frameCount * 0.05 + star.x) * 127 + 127;
      fill(255, 255, 255, star.twinkle);
      noStroke();
      circle(star.x, star.y, star.size);
    }

    fill(255, 255, 200, 150); 
    textStyle(ITALIC);
    text(currentText, width/2, height/4);

  }

  //clock
  for(let h = 0; h <= hr%12+1; h++){
    let col = colors[h];
    if(h!=hr%12+1){drawhour(h-1,col); }
    if(h === hr%12+1) {  
      for(let m = 0; m < mn; m++){
        drawminute(h,m,col);
      }
    } else {  
      for(let m = 0; m < 60; m++){
        drawminute(h,m,col);
      }
    }
  }
  drawsecond(hr%12,mn,sc,colors[hr%12+1]);

  for (let i = fireworks.length - 1; i >= 0; i--) {
    let particles = fireworks[i];
    for (let j = particles.length - 1; j >= 0; j--) {
      let particle = particles[j];
      particle.update();
      particle.display();
      if (particle.isDead()) {
        particles.splice(j, 1);
      }
    }
    if (particles.length === 0) {
      fireworks.splice(i, 1);
    }
  }
}

function shuffleArray(array) {
  for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(random(i + 1));
    [array[i], array[j]] = [array[j], array[i]];
  }
  return array;
}

function drawhour(h,col)
{
  fill(col);
  noStroke();
  let x=(width-areaW)/2-25+areaW;
  let y=height-rectH/2-25-h*rectH;
  rect(x,y+2,50,46);
}
function drawminute(h,m,col)
{
  let x=m*rectW;
  let y=height-h*rectH;
  col_new=[col[0]-120+2*m,col[1]-120+2*m,col[2]-120+2*m,100+2*m];
  fill(col_new);
  rect(x,y,rectW,rectH);
}
function drawsecond(h,m,s,col) {
  fill(col);
  let x=m*rectW;

  let divide_h=(height-(h+1)*rectH)/60;
  let y=s*divide_h;
  rect(x,y,rectW,rectH);
}

function mousePressed() {
  let particles = [];
  let randomColor = colors[floor(random(colors.length))];
  
  for (let i = 0; i < PARTICLE_COUNT; i++) {
    particles.push(new Particle(mouseX, mouseY, randomColor));
  }
  fireworks.push(particles);
  currentText = random(texts);
}

function drawCloud(x, y, size) {
  ellipse(x, y, size * 1.3, size);
  ellipse(x - size/2, y, size);
  ellipse(x + size/2, y, size);
  ellipse(x - size/4, y - size/3, size * 0.8);
  ellipse(x + size/4, y - size/3, size * 0.8);
}