(function (angular) {
  'use strict';
  
  function NavDirective ($location, $anchorScroll) {
    function NavLink ($scope) {
      $scope.select = function (nav) {
        if (nav.selected === true) {
          return;
        }
        
        $scope.navList.map(function (elem) {
          elem.selected = false;
        });
        nav.selected = true;

        $location.hash(nav.id);
        $anchorScroll();
      }
    }
    
    return {
      restrict: 'E',
      replace: true,
      scope: { navList: '=' },
      template: '<div>' +
                  '<a ng-repeat="nav in navList" ng-class="{selected: nav.selected}" ng-click="select(nav)">{{nav.name}}</a>' +
                '</div>',
      link: NavLink
    };
  }
  
  NavDirective.$inject = ['$location', '$anchorScroll'];
  
  angular.module('scDirectives').directive('scNav', NavDirective);
}(angular));