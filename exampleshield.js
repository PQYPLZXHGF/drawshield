/* Copyright 2012 Karl R. Wilcox

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */
   
var version = "0.1";

var examples = new Array (
  'Gules, on a bend or between two escallops argent a Cornish Chough proper between as many cinquefoils azure; and on a chief of the second a rose of the first seeded gold and barbed vert between two fleurs-de-lis of the field - for Petre ', 
  'England impaled with France',
  'Argent a pale gules double cotticed wavy or',
  'Celestial azure, 3 bendlets sable the outer invected, the inner raguly'
);

function drawExample() {
  var index = document.forms['myform'].exnum.selectedIndex;
  var exampleBlazon = examples[index];
  document.forms['myform'].blazon.value = exampleBlazon;
  setupshield('shieldimg',400,exampleBlazon);
}
