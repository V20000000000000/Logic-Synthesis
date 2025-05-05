// Benchmark "C17.iscas" written by ABC on Mon May  5 23:48:41 2025

module \C17.iscas  ( 
    \1GAT(0) , \2GAT(1) , \3GAT(2) , \6GAT(3) , \7GAT(4) ,
    \22GAT(10) , \23GAT(9)   );
  input  \1GAT(0) , \2GAT(1) , \3GAT(2) , \6GAT(3) , \7GAT(4) ;
  output \22GAT(10) , \23GAT(9) ;
  wire new_n8, new_n9, new_n10, new_n12;
  NAND1 g0(.A(\3GAT(2) ), .B(\1GAT(0) ), .Y(new_n8));
  NAND1 g1(.A(\6GAT(3) ), .B(\3GAT(2) ), .Y(new_n9));
  NAND1 g2(.A(new_n9), .B(\2GAT(1) ), .Y(new_n10));
  NAND1 g3(.A(new_n10), .B(new_n8), .Y(\22GAT(10) ));
  NAND1 g4(.A(new_n9), .B(\7GAT(4) ), .Y(new_n12));
  NAND1 g5(.A(new_n12), .B(new_n10), .Y(\23GAT(9) ));
endmodule


