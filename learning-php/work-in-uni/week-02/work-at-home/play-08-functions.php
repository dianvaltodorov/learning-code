<!DOCTYPE html>
<html>
  <head>
    <title>Example</title>
  </head>
  <body>
    <?php

      function sum($first, $second) {
        return $first + $second;
      }
      echo sum(2,3);
      echo "<br>";

      function takesArray($input){
        echo "$input[0] + $input[1] = ", sum($input[0], $input[1]);
      }
      takesArray($array = array(1,2,3,4,5));

      echo "<br>";
      function makeCoffee($type = "cappuccino"){
        return "Make a cup of $type.\n";
      }

      echo makeCoffee();
      echo makeCoffee(null);
      echo makeCoffee("espresso");

      ?>
  </body>
</html>
