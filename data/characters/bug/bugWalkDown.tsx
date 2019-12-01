<?xml version="1.0" encoding="UTF-8"?>
<tileset name="bugWalkDown" tilewidth="128" tileheight="128" tilecount="64" columns="8">
 <image source="bugWalkDown.png" width="1024" height="1024"/>
 <tile id="0" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="Bug"/>
   <property name="ANIMATION_TYPE" value="WALK"/>
   <property name="DIRECTION" value="DOWN"/>
  </properties>
  <objectgroup draworder="index"/>
  <animation>
   <frame tileid="0" duration="25"/>
   <frame tileid="1" duration="25"/>
   <frame tileid="2" duration="25"/>
   <frame tileid="3" duration="25"/>
   <frame tileid="4" duration="25"/>
   <frame tileid="5" duration="25"/>
   <frame tileid="6" duration="25"/>
   <frame tileid="7" duration="25"/>
   <frame tileid="8" duration="25"/>
   <frame tileid="9" duration="25"/>
   <frame tileid="10" duration="25"/>
   <frame tileid="11" duration="25"/>
   <frame tileid="12" duration="25"/>
   <frame tileid="13" duration="25"/>
   <frame tileid="14" duration="25"/>
   <frame tileid="15" duration="25"/>
   <frame tileid="16" duration="25"/>
   <frame tileid="17" duration="25"/>
   <frame tileid="18" duration="25"/>
   <frame tileid="19" duration="25"/>
   <frame tileid="20" duration="25"/>
   <frame tileid="21" duration="25"/>
   <frame tileid="22" duration="25"/>
   <frame tileid="23" duration="25"/>
   <frame tileid="24" duration="25"/>
   <frame tileid="25" duration="25"/>
   <frame tileid="26" duration="25"/>
   <frame tileid="27" duration="25"/>
   <frame tileid="28" duration="25"/>
   <frame tileid="29" duration="25"/>
   <frame tileid="30" duration="25"/>
   <frame tileid="31" duration="25"/>
   <frame tileid="32" duration="25"/>
   <frame tileid="33" duration="25"/>
   <frame tileid="34" duration="25"/>
   <frame tileid="35" duration="25"/>
   <frame tileid="36" duration="25"/>
   <frame tileid="37" duration="25"/>
   <frame tileid="38" duration="25"/>
   <frame tileid="39" duration="25"/>
   <frame tileid="40" duration="25"/>
   <frame tileid="41" duration="25"/>
   <frame tileid="42" duration="25"/>
   <frame tileid="43" duration="25"/>
   <frame tileid="44" duration="25"/>
   <frame tileid="45" duration="25"/>
   <frame tileid="46" duration="25"/>
   <frame tileid="47" duration="25"/>
   <frame tileid="48" duration="25"/>
   <frame tileid="49" duration="25"/>
   <frame tileid="50" duration="25"/>
   <frame tileid="51" duration="25"/>
   <frame tileid="52" duration="25"/>
   <frame tileid="53" duration="25"/>
   <frame tileid="54" duration="25"/>
   <frame tileid="55" duration="25"/>
   <frame tileid="56" duration="25"/>
   <frame tileid="57" duration="25"/>
   <frame tileid="58" duration="25"/>
  </animation>
 </tile>
 <tile id="1" type="ACTOR_TEMPLATE">
  <properties>
   <property name="ACTOR_NAME" value="Bug"/>
   <property name="ANIMATION_TYPE" value="WALK"/>
   <property name="DIRECTION" value="DOWN"/>
   <property name="base_speed" type="float" value="250"/>
   <property name="checkpoint1" value="P1_1"/>
   <property name="checkpoint2" value="P1_2"/>
   <property name="checkpoint3" value="P1_3"/>
   <property name="checkpoint4" value="P1_4"/>
   <property name="type" value="SmallEnemy"/>
  </properties>
  <objectgroup draworder="index">
   <object id="1" x="40" y="40" width="50" height="50"/>
  </objectgroup>
 </tile>
</tileset>
