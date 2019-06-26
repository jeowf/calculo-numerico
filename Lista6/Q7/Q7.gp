set terminal png
set output "img7.png"
set xrange[-2.5:7.5]
plot -0.7869/2 - (0.7833/2)*cos(3*pi*((x-2)/4))-1.2878*cos(pi*((x-2)/4)) -0.7658*sin(pi*((x-2)/4)) + 0.6610*cos(pi*((x-2)/2)) - 1.8801*sin(pi*((x-2)/2)) lc 8 title "S3(x)", x*cos(x) + sin(2*x) lc 9
quit
