# Miller–Rabin primality test
<pre>
<b>Input #1</b>: <i>n</i> &gt; 3, an odd integer to be tested for primality
<b>Input #2</b>: <i>k</i>, the number of rounds of testing to perform
<b>Output</b>: “<i>composite</i>” if <i>n</i> is found to be composite, “<i>probably prime</i>” otherwise

write <i>n</i> as 2<sup><i>r</i></sup>·<i>d</i> + 1 with <i>d</i> odd (by factoring out powers of 2 from <i>n</i> − 1)
WitnessLoop: <b>repeat</b> <i>k</i> <b>times</b>:
   pick a random integer <i>a</i> in the range [2, <i>n</i> − 2]
   <i>x</i> ← <i>a</i><sup><i>d</i></sup> mod <i>n</i>
   <b>if</b> <i>x</i> = 1 or <i>x</i> = <i>n</i> − 1 <b>then</b>
      <b>continue</b> WitnessLoop
   <b>repeat</b> <i>r</i> − 1 <b>times</b>:
      <i>x</i> ← <i>x</i><sup>2</sup> mod <i>n</i>
      <b>if</b> <i>x</i> = <i>n</i> − 1 <b>then</b>
         <b>continue</b> WitnessLoop
   <b>return</b> “<i>composite</i>”
<b>return</b> “<i>probably prime</i>”
</pre>