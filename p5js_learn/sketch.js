function setup() {
    createCanvas(400, 400);
    for (let i = 1; i <= 12; i++) {
      let H = height / 12;
      let Line = width * 2 / 3;
      let pointer1 = 0;
      let count=i%2
      fill(0, 0, 0);
      // if (i % 2 != 0) {
      //   widthnow += H;
      // }
      for (let j = H; pointer1 <= Line; j *= 9/10) {
        if(count==1)
          {
            count=0
            pointer1 += j
            continue
          }
        rect(pointer1, (i - 1) * H, j, H);
        pointer1 += j;
        count=1
      }
        
      let pointer2=width
        for (let j = H; pointer2 >= Line; j *= 31/40) {
        if(count==1)
          {
            count=0
            pointer2 -= j
            continue
          }
        rect(pointer2, (i - 1) * H, j, H);
        pointer2 -= j;
        count=1
      }
    }
  }