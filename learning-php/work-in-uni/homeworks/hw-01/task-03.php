  <!DOCTYPE html>
<html>
  <head>
    <title>Example</title>
  </head>
  <body>
    <?php
    class Request{
        protected $server;

        public function __construct($mServer){
           $this->server = $mServer;
            var_dump($this->server);
        }
        public function getMethod(){return strtolower($this->server["REQUEST_METHOD"]);}
        public function getPath(){return $this->server["PHP_SELF"];}
        public function getURL(){return $this->server["REQUEST_URI"];}
        public function getUserAgent(){return $this->server["HTTP_USER_AGENT"];}
      }

      class GetRequest extends  Request{
        function getData()
        {
          var_dump($_GET);
          return json_encode($this->server["argv"][0]);
        }
      }
    ?>
  </body>
</html>
