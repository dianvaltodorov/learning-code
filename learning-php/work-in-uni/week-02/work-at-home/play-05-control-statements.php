<!DOCTYPE html>
<html>
  <head>
    <title>Example</title>
  </head>
  <body>
    <?php

      $a = 3;
      $b = 3;

      if($a > $b) {
        echo "a is bigger than b";
      }elseif ($a==$b) {
        echo "a is equal to b";
      }else{
        echo "a is smaller than b";
      }

      echo "<br>";

      $favcolor = "red";

      switch ($favcolor) {
          case "red":
              echo "Your favorite color is red!";
              break;
          case "blue":
              echo "Your favorite color is blue!";
              break;
          case "green":
              echo "Your favorite color is green!";
              break;
          default:
              echo "Your favorite color is neither red, blue, nor green!";
      }
      echo "<br>";

    ?>
  </body>
</html>
