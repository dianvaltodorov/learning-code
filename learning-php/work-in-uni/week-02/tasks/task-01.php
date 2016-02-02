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
        'go' => array(
          'title' => 'Programming with Go',
          'description' => '...',
          'lecturer' => 'Bachiiski',
        )
      );

      function show_page($pageId, $data){
        $output = "<h1>";
        $output = $output.$data[$pageId]['title'];
        $output = $output."</h1>";

        $output = $output."<h2>";
        $output = $output.$data[$pageId]['lecturer'];
        $output = $output."</h2>";

        $output =  $output."<p>";
        $output = $output.$data[$pageId]['description'];
        $output = $output."</p>";
        echo $output;
        // $output = "<h1>";
        // $output .= $data[$pageId]
        // <h1>Компютърна графика с WebGL</h1>
        // <h2>доц. П. Бойчев</h2>
        // <p>...</p>
      }

      show_page('webgl', $data);

    ?>
  </body>
</html>
