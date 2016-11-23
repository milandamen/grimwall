#!python3

import xml.etree.ElementTree as ET

levelname = "level1_remake"
namespace = "grimwall"
tilt = "60"
rotation = "45"
viewport_x = "0"
viewport_y = "0"
viewport_width = "1024"
viewport_height = "768"
ref_cell_width = "98"
ref_cell_height = "48"

objects = {}
layers = []

root = ET.parse("assets/tiled/" + levelname + ".tmx").getroot()

for child in root:
    if child.tag == "tileset":
        firstgid = child.attrib["firstgid"]
        if child.attrib["tilecount"] == "1":
            source = child[0].attrib["source"][:-4] + ".xml"
            sourceSplitted = source.split("/")
            name = sourceSplitted[len(sourceSplitted)-1][:-4]
            objects[firstgid] = (firstgid, name, source)
        else:
            for tile in child:
                source = tile[0].attrib["source"][:-4] + ".xml"
                sourceSplitted = source.split("/")
                name = sourceSplitted[len(sourceSplitted)-1][:-4]
                gid = str(int(firstgid) + int(tile.attrib["id"]))
                objects[gid] = (gid, name, source)
        
    elif child.tag == "layer":
        name = child.attrib["name"]
        width = child.attrib["width"]
        height = child.attrib["height"]
        data = child[0].text.replace("\n","").split(",")
        
        tiles = []
        for tile in data:
            if tile is "0":
                tiles.append("")
            elif tile in objects:
                tiles.append(objects[tile][1])
        
        layers.append((name, width, height, tiles))


# From http://stackoverflow.com/a/33956544
# Pretty print the xml file
def indent(elem, level=0):
    i = "\n" + level*"    "
    if len(elem):
        if not elem.text or not elem.text.strip():
            elem.text = i + "    "
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
        for elem in elem:
            indent(elem, level+1)
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
    else:
        if level and (not elem.tail or not elem.tail.strip()):
            elem.tail = i


fiferoot = ET.Element("map")
fiferoot.set("id", levelname)
fiferoot.set("format", "1.0")

# Imports
for gid, obj in objects.items():
    imp = ET.SubElement(fiferoot, "import")
    imp.set("file", obj[2])

# Layers
for layer in layers:
    lay = ET.SubElement(fiferoot, "layer")
    lay.set("id", layer[0])
    lay.set("x_offset", "0")
    lay.set("y_offset", "0")
    lay.set("z_offset", "0")
    lay.set("x_scale", "1")
    lay.set("y_scale", "1")
    lay.set("rotation", "0")
    lay.set("grid_type", "square")
    lay.set("transparency", "0")
    lay.set("pathing", "cell_edges_only")
    lay.set("sorting", "camera")
    
    width = int(layer[1])
    height = int(layer[2])
    startX = 0 - int(width / 2)      # Make the map centered
    startY = 0 - int(height / 2)     # Make the map centered
    
    # Tiles
    # Tiled maps have x and y rotated clockwise 90deg in comparison to FIFE maps
    instances = ET.SubElement(lay, "instances")
    count = 0
    x = width
    y = 0
    firstReal = True
    for tile in layer[3]:
        if tile != "":
            t = ET.SubElement(instances, "i")
            if firstReal:
                t.set("ns", namespace)
                firstReal = False
            t.set("o", tile)
            t.set("x", str(startX + x))
            t.set("y", str(startY + y))
            t.set("z", "0")
            t.set("r", "0")
            t.set("blocking", "1")
            t.set("stackpos", "0")
        
        count += 1
        x = width - int(count / width)
        y = count % width

# Cellcaches
ET.SubElement(fiferoot, "cellcaches")

# Camera
camera = ET.SubElement(fiferoot, "camera")
camera.set("id", "main")
camera.set("ref_layer_id", layers[0][0])
camera.set("zoom", "1")
camera.set("tilt", tilt)
camera.set("rotation", rotation)
camera.set("viewport", viewport_x + "," + viewport_y + "," + viewport_width + "," + viewport_height)
camera.set("ref_cell_width", ref_cell_width)
camera.set("ref_cell_height", ref_cell_height)

indent(fiferoot)
fifetree = ET.ElementTree(fiferoot)
fifetree.write("assets/maps/level1_remake_conv.xml", encoding="ascii", xml_declaration=True)
