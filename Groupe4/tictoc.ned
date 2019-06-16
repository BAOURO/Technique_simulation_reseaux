//
simple Tic8
{
    parameters:
        @display("i=device/pc4");
    gates:
        input in;
        output out;
}

simple Toc8
{
    parameters:
        @display("i=device/pc4");
    gates:
        input in;
        output out;
}

network Tictoc8
{
    submodules:
        ordi1: Tic8 {
            parameters:
                @display("i=,cyan");
        }
        ordi2: Toc8 {
            parameters:
                @display("i=,gold;p=52,68");
        }
    connections:
        ordi1.out --> {  delay = 150ms; } --> ordi2.in;
        ordi1.in <-- {  delay = 150ms; } <-- ordi2.out;
}
