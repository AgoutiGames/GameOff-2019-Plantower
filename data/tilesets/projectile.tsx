<?xml version="1.0" encoding="UTF-8"?>
<tileset name="projectile" tilewidth="32" tileheight="32" tilecount="4" columns="4">
 <image source="projectile.png" width="128" height="32"/>
 <tile id="0" type="ACTOR_TEMPLATE">
  <properties>
   <property name="ACTOR_NAME" value="Projectile"/>
   <property name="ANIMATION_TYPE" value="IDLE"/>
   <property name="type" value="Projectile"/>
  </properties>
  <objectgroup draworder="index">
   <object id="1" name="HIT" x="2" y="2" width="28" height="28"/>
  </objectgroup>
 </tile>
 <tile id="1" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="Projectile"/>
   <property name="ANIMATION_TYPE" value="IDLE"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="0" duration="100"/>
   <frame tileid="1" duration="100"/>
   <frame tileid="2" duration="100"/>
   <frame tileid="3" duration="100"/>
  </animation>
 </tile>
</tileset>
