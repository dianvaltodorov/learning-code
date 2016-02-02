(ns yolo-repl.views.main
  (:require [yolo-repl.views.common :as common])
  (:use [noir.core :only [defpage]]
        [hiccup.core :only [html]]))

(defpage "/" []
         (common/layout
           [:div#content]))
