(require 'cljs.build.api)

(cljs.build.api/watch "src"
  {:main 'hello-world.core
   :output-to "out/main.js"})
