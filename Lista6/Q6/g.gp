set terminal png
set output "img6.png"
set grid
set xrange [1:4]
plot cos(x), 0.34*(x*x - 5*x + 5.5) - 0.44*(x-2.5) - 0.53
quit
