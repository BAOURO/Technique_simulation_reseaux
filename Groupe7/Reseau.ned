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


simple Ordi1
{
    parameters:
        @display("i=device/pc4");
    gates:
        input in;
        output out;
}

simple Ordi2
{
    parameters:
        @display("i=device/pc4");
    gates:
        input in;
        output out;
}

network reseau
{
    types:
    submodules:
        ordi1: Ordi1 {
            @display("i=,cyan");
        }
        ordi2: Ordi2 {
            @display("i=,gold");
        }
    connections:
        ordi1.out --> {  delay = 100ms; } --> ordi2.in;
        ordi1.in <-- {  delay = 100ms; } <-- ordi2.out;


}
