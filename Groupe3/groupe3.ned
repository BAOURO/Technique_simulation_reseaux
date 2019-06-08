//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

simple Sender
{
    gates:
        input in;
        output out;
}

simple Receiver
{
    gates:
        input in;
        output out;
}

network Groupe3
{
    submodules:
        Ordi1: Sender {
            @display("p=68,109;t=Envoyeur,,#0000A0");
        }
        Ordi2: Receiver {
            @display("t=Receveur,,#008000;p=321,211");
        }
    connections:
        Ordi1.out --> {  delay = 5s; } --> Ordi2.in;
        Ordi1.in <-- {  delay = 5s; } <-- Ordi2.out;
}

