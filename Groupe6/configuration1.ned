

simple Pc1
{
    parameters:
        @display("i=block/routing");
    gates:
        input in;
        output out;
}

simple Pc2
{
    parameters:
        @display("i=block/routing");
    gates:
        input in;
        output out;
}


network Configuration1
{
    submodules:
        pc1: Pc1 {
            parameters:
                @display("i=block/app2,grey;p=18,265");
        }
        pc2: Pc2 {
            parameters:
                @display("i=block/app2,grey;p=171,121");
        }
    connections:
        pc1.out --> {  delay = 150ms; } --> pc2.in;
        pc1.in <-- {  delay = 150ms; } <-- pc2.out;
}
