<!DOCTYPE html>
<html>
  <head>
    <title>Example</title>
  </head>
  <body>
    <?php
       $arr = array('foo' => "bar", "joo" => "haz");

       $nums = array(1,2,3,4);

       foreach ($arr as $key) {
          echo $key."\n";
          echo "<br>";
       }

       echo "<br>";
       foreach ($arr as $key => $value) {
          echo "$key => $value";
          echo "<br>";
       }

       echo "<br>";
       foreach ($nums as $key) {
          echo $key."\n";
          echo "<br>";
       }
       echo "<br>";

       foreach ($nums as $key => $value) {
          echo "$key => $value";
          echo "<br>";
       }
       echo "<br>";

       $colors = array("red", "green", "blue", "yellow");
       foreach ($colors as $value) {
           echo "$value <br>";
       }

       echo "<br>";
       echo "The third element of color is: ";
       echo $colors[2];
       echo "<br>";


       echo "The thirs element of color is: ";
       echo $arr['foo'];
       echo "<br>";
    ?>
  </body>
</html>
