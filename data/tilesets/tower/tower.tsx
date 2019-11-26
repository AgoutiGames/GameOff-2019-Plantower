<?xml version="1.0" encoding="UTF-8"?>
<tileset name="tower" tilewidth="256" tileheight="256" tilecount="3" columns="3">
 <image source="tower.png" width="768" height="256"/>
 <tile id="0" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="Tower"/>
   <property name="ANIMATION_TYPE" value="IDLE"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="2" duration="1000"/>
   <frame tileid="0" duration="1000"/>
   <frame tileid="1" duration="1000"/>
  </animation>
 </tile>
 <tile id="2" type="ACTOR_TEMPLATE">
  <properties>
   <property name="ACTOR_NAME" value="Tower"/>
   <property name="ANIMATION_TYPE" value="IDLE"/>
   <property name="type" value="Tower"/>
  </properties>
  <objectgroup draworder="index">
   <object id="1" name="ActivateRange" x="80" y="164" width="95" height="98"/>
  </objectgroup>
 </tile>
</tileset>
