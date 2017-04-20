set boxwidth 0.5
set style fill solid
set yrange [0:]
  set style line 1 lt 2 lw 4 pt 3 ps 0.5
  set style function lines
plot "graf6.dat" w boxes, "graf7.dat" w lp ls 1
