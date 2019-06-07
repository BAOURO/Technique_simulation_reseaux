

simple Ordi1
{
    parameters:
        @display("i=block/routing");
    gates:
        input in;
        output out;
}

simple Ordi2
{
    parameters:
        @display("i=block/process");
    gates:
        input in;
        output out;
}

network Config1
{
    submodules:
        ordi1: Ordi1 {
            parameters:
                @display("i=block/app2,grey;p=18,265");
        }
        ordi2: Ordi2 {
            parameters:
                @display("i=block/app2,grey;p=171,121");
        }
    connections:
        ordi1.out --> {  delay = 100ms; } --> ordi2.in;
        ordi1.in <-- {  delay = 100ms; } <-- ordi2.out;
}
