<<<<<<< HEAD
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

network Configuration1
{
    submodules:
        ordi1: Ordi1 {
            parameters:
                @display("i=device/laptop,grey;p=78,280");
        }
        ordi2: Ordi2 {
            parameters:
                @display("i=device/laptop,grey;p=171,121");
        }
    connections:
        ordi1.out --> {  delay = 100ms; } --> ordi2.in;
        ordi1.in <-- {  delay = 100ms; } <-- ordi2.out;
}
=======
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

network Configuration1
{
    submodules:
        ordi1: Ordi1 {
            parameters:
                @display("i=device/laptop,grey;p=78,280");
        }
        ordi2: Ordi2 {
            parameters:
                @display("i=device/laptop,grey;p=171,121");
        }
    connections:
        ordi1.out --> {  delay = 100ms; } --> ordi2.in;
        ordi1.in <-- {  delay = 100ms; } <-- ordi2.out;
}
>>>>>>> d5904819cc100adf91884c3a8cb39cc199cb3a0b
