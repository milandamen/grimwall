(function(name,data){
 if(typeof onTileMapLoaded === 'undefined') {
  if(typeof TileMaps === 'undefined') TileMaps = {};
  TileMaps[name] = data;
 } else {
  onTileMapLoaded(name,data);
 }})("level1",
{ "height":15,
 "layers":[
        {
         "data":[3, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 1, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 1, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 1, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 1, 2, 3, 3, 3],
         "height":15,
         "name":"Tile Layer 1",
         "opacity":1,
         "type":"tilelayer",
         "visible":true,
         "width":15,
         "x":0,
         "y":0
        }, 
        {
         "data":[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         "height":15,
         "name":"Tile Layer 2",
         "opacity":1,
         "type":"tilelayer",
         "visible":true,
         "width":15,
         "x":0,
         "y":0
        }],
 "nextobjectid":1,
 "orientation":"isometric",
 "renderorder":"right-down",
 "tileheight":48,
 "tilesets":[
        {
         "columns":1,
         "firstgid":1,
         "image":"..\/ClionProjects\/grimwall\/assets\/objects\/tiles\/gravell.png",
         "imageheight":48,
         "imagewidth":98,
         "margin":0,
         "name":"gravell",
         "spacing":0,
         "tilecount":1,
         "tileheight":48,
         "tilewidth":98
        }, 
        {
         "columns":1,
         "firstgid":2,
         "image":"..\/ClionProjects\/grimwall\/assets\/objects\/tiles\/sand.png",
         "imageheight":48,
         "imagewidth":98,
         "margin":0,
         "name":"sand",
         "spacing":0,
         "tilecount":1,
         "tileheight":48,
         "tilewidth":98
        }, 
        {
         "columns":1,
         "firstgid":3,
         "image":"..\/ClionProjects\/grimwall\/assets\/objects\/tiles\/grass.png",
         "imageheight":48,
         "imagewidth":98,
         "margin":0,
         "name":"grass",
         "spacing":0,
         "tilecount":1,
         "tileheight":48,
         "tilewidth":98
        }, 
        {
         "columns":1,
         "firstgid":4,
         "image":"..\/ClionProjects\/grimwall\/assets\/objects\/towers\/tower.png",
         "imageheight":144,
         "imagewidth":98,
         "margin":0,
         "name":"tower",
         "spacing":0,
         "tilecount":1,
         "tileheight":144,
         "tilewidth":98
        }],
 "tilewidth":98,
 "version":1,
 "width":15
});