<!DOCTYPE html>
<html>
  <head>
    <title>Example</title>
  </head>
  <body>
    <?php

      $data = array(
        'webgl' => array(
          'title' => 'Computer graphics with WebGL',
          'description' => '...',
          'lecturer' => 'Boychev',
        ),
        'foo' => array(
          'title' => 'Foo Programming',
          'description' => '...',
          'lecturer' => 'Bachiiski',
        ),
        'roo' => array(
          'title' => 'Roo structures and analysis',
          'description' => '...',
          'lecturer' => 'Bachiiski',
        ),
        'bar' => array(
          'title' => 'Bars and Jars',
          'description' => '...',
          'lecturer' => 'Bachiiski',
        ),
        'tap' => array(
          'title' => 'Tap Clap',
          'description' => '...',
          'lecturer' => 'Bachiiski',
        )
      );

      function show_nav($data, $currentCourese){
        $output = "<nav>";
        foreach ($data as $key => $value) {
          if($key === $currentCourese) {
            $output = $output."<a href=\"?page=";
            $output = $output.$key;
            $output = $output."\" class=\"selected\">";
            $output = $output.$data[$key]['title'];
            $output = $output."</a>";
          }else {
            $output = $output."<a href=\"?page=";
            $output = $output.$key;
            $output = $output."\">";
            $output = $output.$data[$key]['title'];
            $output = $output."</a>";
          }
          $output = $output;
        }
        $output = $output."</nav>";
        return $output;
      }

      echo show_nav($data, 'webgl');
    ?>
  </body>
</html>
