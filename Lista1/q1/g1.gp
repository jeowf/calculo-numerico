set terminal eps
set output "img1.eps"
set xrange[-1.5:2.5]
set xzeroaxis lt 3 lw 2 lc rgb 'black'
set yzeroaxis lt 3 lw 2 lc rgb 'black'
set grid
set xtics 0.5

plot x**3 - 2 * x**2 - x + 2 title "função cúbica", -2*x + 2 title "reta tangente em x = 1", "./coord1.txt" title "pontos de interesse", 2.1 title "reta tangente ao 1º ponto crítico", -0.63 title "reta tangente ao 2º ponto crítico"
quit
