void setup() 
{
    size(600, 300);
    background(0, 0, 0);
}

int time = 0;
                                          
void draw()
{
    background(200, time, time);
    stroke(0);
    fill(255, 255, 0);
    int x = sin(time * 0.1) * time * 0.2;
    ellipse(150 - time * 0.1, 150 + x, 75, 75 + sin(time * 0.1) * 10);
    ellipse(225 + time * 0.1, 150 + x, 75, 75 + sin(time * 0.1) * 10);
    fill(0);
    ellipse(150 - time * 0.1, 150 + x * 0.8, 30, 30);
    ellipse(225 + time * 0.1, 150 + x * 0.8, 30, 30);
    fill(0, 0, 255);

    time = time + 1;
}
