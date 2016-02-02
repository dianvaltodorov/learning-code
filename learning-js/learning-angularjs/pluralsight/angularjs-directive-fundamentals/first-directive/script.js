angular.module("app", []);

angular.module("app").controller("mainCtrl", function($scope){
  $scope.message = "Mido"
  $scope.user = {
    name:  "Luke Sky",
    address: {
      city:"Veliko Tarnovo",
      planet:"Earth",
      street:"Bqla Bona"
    },
    friends: [
      "Kido",
      "Vido",
      "Jido"
    ]
  }
});

angular.module("app").directive("userInfoCard", function(){
  return {
    templateUrl: "userInfoCard.html",
    restrict:"E",
    replace:true
  }
});  