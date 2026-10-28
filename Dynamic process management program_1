begin
m=4; n=2;
p1;
fork w2; fork w3; fork w6; quit;
w2:p2; join (m,w9); quit;
w3:p3; fork (w4); fork(w5); quit;
w4:p4; join (m,w9); quit;
w5:p5; join (m,w9); quit;
w6:p6; join (m, w9); quit;
w9; fork(w7); fork(w8); quit;
w7:p7; join (n,w10); quit;
w8:p8; join (n,w10); quit;
w10; quit
end


//The fourth graph
begin
m=2; n=3;
p1; fork w2; fork w5; fork w7; quit;
w2:p2; fork (w4); fork (w3); quit;
w4:p4; join(m,w6); quit;
w5:p5; join(m,w6); quit;
w6:p6; join (n,w8), quit;
w3:p3; join (n,w8); quit;
w7:p7; join (n,w8);quit;
w8:p8;quit;
end

//Graph exo 2
begin
m=2; n=2;
fork (w1); fork (w2); fork (w3);
w1:p1; join (m,w4); quit;
w2:p2; join (m;w4); quit;
w3:p3; join (n,w5); quit;
w4:p4; join (n,w5); quit;
w5:p5; quit;
end
