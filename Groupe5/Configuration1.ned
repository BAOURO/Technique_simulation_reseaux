

simple Ordi_1
{
    parameters:
        @display("i=block/routing");
    gates:
        input in;
        output out;
}

simple Ordi_2
{
    parameters:
        @display("i=block/process");
    gates:
        input in;
        output out;
}

network Conf1
{
    submodules:
        Ordi1: Ordi_1 {
            parameters:
                @display("i=,cyan");
        }
        Ordi2: Ordi_2 {
            parameters:
                @display("i=,gold");
        }
    connections:
        Ordi1.out --> {  delay = 5s; } --> Ordi2.in;
        Ordi1.in <-- {  delay = 5s; } <-- Ordi2.out;
}
