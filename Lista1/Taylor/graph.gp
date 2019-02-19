set terminal eps
set output "img3.eps"
set xrange[-10:10]
set yrange[-10:10]
set grid
set xtics 1
plot x * cos(x), x + (-x**3)/2 + (x**5)/24
quit
