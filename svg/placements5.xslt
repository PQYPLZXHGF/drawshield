<?xml version="1.0" encoding="ISO-8859-1"?>
<!-- Copyright 2010 Karl R. Wilcox 

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. -->
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl">
  <xsl:output method="xml" omit-xml-declaration="no" indent="no"/>
  <xsl:strip-space elements="*"/>
  <xsl:param name="region" select="'pl'"/>
  <!-- ========================= -->
  <!-- Set Placements            -->
  <!-- ========================= -->
  <xsl:template match="charge">
    <xsl:param name="region"/>
    <!-- Is this charge on a shield that contains a chief, or on/between an ordinary on a shield containing a chief -->
    <xsl:variable name="chief"><xsl:value-of select="string(boolean(../../../ordinary[@type='chief'] or ../ordinary[@type='chief']))"/></xsl:variable> 
    <xsl:variable name="conjoin"><xsl:value-of select="boolean(modifier/@name[.='conjoin'])"></xsl:value-of></xsl:variable>
    <xsl:variable name="number">
      <xsl:choose>
        <xsl:when test="modifier[@name='between']"><xsl:value-of select="@number + modifier[@name='between']/charge/@number"/></xsl:when>
        <xsl:otherwise><xsl:value-of select="@number"/></xsl:otherwise>
      </xsl:choose>
    </xsl:variable>
    <xsl:variable name="boundingBox">
      <xsl:choose>
        <xsl:when test="$chief='false'">150,200,700,700</xsl:when>
        <xsl:otherwise>150,350,700,600</xsl:otherwise>
      </xsl:choose>
    </xsl:variable>
    <charge>
      <xsl:apply-templates select="*|@*">
        <xsl:with-param name="region"><xsl:value-of select="$region"/></xsl:with-param>
      </xsl:apply-templates>
    <xsl:variable name="placement">
    <xsl:choose>
      <!-- Strewn on a field -->
      <xsl:when test="parent::semyde"/><!-- Do nothing -->
      <!-- Between (around) another charge -->
      <xsl:when test="parent::modifier[@name='between']/parent::charge"/> <!-- Do nothing -->
      <!-- A charge which is between others -->
      <xsl:when test="modifier[@name='between']/charge[@number > 2]">
        <xsl:choose>
          <xsl:when test="@type='quadrate'">x/x/x/x/200,300,160,160:500,600,600,600:800,300,160,160:200,900:800,900</xsl:when>
          <xsl:when test="$chief='false'">x/x/x/250,200,300,280:500,550,700,400:750,200,300,280:500,1000/250,200,280,280:500,550,700,400:750,200,280,280:250,900:750,900/250,200,240,240:500,550,700,400:750,200,240,240:500,200:250,900:750,900</xsl:when>
          <xsl:when test="$chief='true'">x/x/x/250,450,160,160:500,700,700,300:750,450,160,160:500,950/250,450,160,160:500,700,700,300:750,450,160,160:250,950:750,950/250,450,160,160:500,700,700,300:750,450,160,160:500,200:250,950:750,950</xsl:when>
        </xsl:choose>
      </xsl:when>
      <!-- On an ordinary  -->
      <xsl:when test="parent::modifier[@name='on']/parent::ordinary">
        <xsl:variable name="ordtype"><xsl:value-of select="../../@type"/></xsl:variable>
        <xsl:variable name="ordsubtype"><xsl:value-of select="../../@subtype"/></xsl:variable>
        <xsl:choose>
          <!-- Test order is important - check specific subtypes before generic type -->
          <xsl:when test="$ordtype='bend' and $chief='false'">500,500,180,180,45/333.33,333.33,180,180,45:666.67,666.67/250,250,180,180,45:500,500:750,750/200,200,180,180,45:400,400:600,600:800,800/166.67,166.67,180,180,45:333.33,333.33:500,500:666.67,666.67:833.33,833.33/142.86,142.86,160,160,45:285.71,285.71:428.57,428.57:571.43,571.43:714.29,714.29:857.14,857.14</xsl:when>
          <xsl:when test="$ordtype='bend' and $chief='true'">500,800,180,180,45/333.33,633.33,180,180,45:666.67,966.67/200,500,180,180,45:400,700:600,900/166.67,466.67,180,180,45:333.33,633.33:500,800:666.67,966.67/142.86,442.86,140,140,45:285.71,585.71:428.57,728.57:571.43,871.43:714.29,1014.29/s</xsl:when>
          <xsl:when test="$ordtype='base'">500,950,500,240/333.33,950,300,200:666.67,950/333.33,900,160,160:666.67,900:500,1050/x/x/x</xsl:when>
          <xsl:when test="$ordsubtype='chief-triangular'">500,200,200,200/375,180,180,180:625,180/325,140,160,180:500,240:675,140/x/x/x</xsl:when>
          <xsl:when test="$ordsubtype='canton'">125,125,200,200/83.33,125,80,200:166.67,125/83.33,83.33,80,90:166.67,83.33:125,166.67/83.33,83.33,80,90:83.33,166.67:166.67,83.33:166.67,166.67/s/s</xsl:when>
          <xsl:when test="$ordsubtype='gyron'">80,200,100,100/s/s/s/s/s</xsl:when>
          <xsl:when test="$ordtype='chief'"><xsl:value-of select="php:function('calcPlace','h',string($number),string($conjoin),'100,50,800,200')" /></xsl:when>
          <xsl:when test="$ordtype='fess'"><xsl:value-of select="php:function('calcPlace','h',string($number),string($conjoin),'100,400,800,200')" /></xsl:when>
          <xsl:when test="$ordsubtype='gore'">130,700,160,160/130,600,140,140:130,800/x/x/x/x</xsl:when>
          <xsl:when test="$ordtype='pale' and $chief='false'"><xsl:value-of select="php:function('calcPlace','v',string($number),string($conjoin),'400,100,200,1000')" /></xsl:when>
          <xsl:when test="$ordtype='pale' and $chief='true'"><xsl:value-of select="php:function('calcPlace','v',string($number),string($conjoin),'400,350,200,750')" /></xsl:when>
          <xsl:when test="$ordtype='tierce' and $chief='false'"><xsl:value-of select="php:function('calcPlace','v',string($number),string($conjoin),'75,100,200,800')" /></xsl:when>
          <xsl:when test="$ordtype='tierce' and $chief='true'"><xsl:value-of select="php:function('calcPlace','v',string($number),string($conjoin),'75,350,200,650')" /></xsl:when>
          <xsl:when test="$ordtype='chevron' and $chief='false'">500,400,100,100/250,625,100,100,45:750,625,,,-45/250,625,100,100,45:500,400,,,0:750,625,,,-45/200,675,100,100,45:400,475:600,475,,,-45:800,675/200,675,100,100,45:350,525:500,400,,,0:650,525,,,-45:800,675/150,725,100,100,45:250,625:350,525:650,525,,,-45:750,625:850,725</xsl:when>
          <xsl:when test="$ordtype='chevron' and $chief='true'">500,550,100,100/250,775,100,100,45:750,775,,,-45/250,775,100,100,45:500,550,,,0:750,775,,,-45/200,825,100,100,45:400,625:600,625,,,-45:800,825/200,825,100,100,45:350,675:500,550,,,0:650,625,,,-45:800,825/150,875,100,100,45:250,775:350,675:650,675,,,-45:750,775:850,875</xsl:when>
          <xsl:when test="$ordtype='cross' and $chief='false'">500,500,200,200//200,500,220,220:800,500:500,250/200,500,200,200:500,220:800,500:500,800//200,500,200,200:500,200:800,500:500,500:500,800:500,1050</xsl:when>
          <xsl:when test="$ordtype='cross' and $chief='true'">500,700,160,160////250,700,160,160:750,700:500,450:500,700:500,950/x</xsl:when>
          <xsl:when test="$ordsubtype='saltire' and $chief='false'">500,500,160,160/x/x/250,250,160,160,-45:750,250,,,45:750,750,,,-45:250,750,,,45/500,500,160,160,0:250,250,,,-45:750,250,,,45:750,750,,,-45:250,750,,,45/x</xsl:when>
          <xsl:when test="$ordsubtype='saltire' and $chief='true'">500,700,160,160/x/x/250,450,160,160,-45:750,450,,,45:750,950,,,-45:250,950,,,45/500,740,160,160,0:250,490,,,-45:750,490,,,45:750,990,,,-45:250,990,,,45/x</xsl:when>
          <xsl:when test="$ordsubtype='inescutcheon' and $chief='false'"><xsl:value-of select="php:function('calcPlace','w',string($number),string($conjoin),'300,300,400,500')" /></xsl:when>
          <xsl:when test="$ordsubtype='inescutcheon' and $chief='true'"><xsl:value-of select="php:function('calcPlace','w',string($number),string($conjoin),'300,600,400,250')" /></xsl:when>
          <xsl:when test="$ordsubtype='pile' and $chief='false'"><xsl:value-of select="php:function('calcPlace','w',string($number),string($conjoin),'300,100,400,300')" /></xsl:when>
          <xsl:when test="$ordsubtype='pile' and $chief='true'"><xsl:value-of select="php:function('calcPlace','w',string($number),string($conjoin),'300,400,400,300')" /></xsl:when>
          <xsl:when test="$ordsubtype='cross-formy' and $chief='false'">x///100,500,120,120:900,500:500,100:500,900/s/s</xsl:when>
          <xsl:when test="$ordsubtype='cross-formy' and $chief='true'">x///100,700,120,120:900,700:500,400:500,1100/s/s</xsl:when>
          <xsl:when test="$ordsubtype='quarter' and $chief='false'">250,250,350,350/150,150,150,150:350,350/150,150,150,150:350,150:250,250/166,166,120,120:334,166:166,334,334,334:100,100,100,100:400,100:250,250:400,100:400,400</xsl:when>
          <xsl:when test="$ordsubtype='quarter' and $chief='true'">t</xsl:when>
          <xsl:otherwise>n</xsl:otherwise>
        </xsl:choose>
      </xsl:when>
      <!-- On particular charges  -->
      <xsl:when test="parent::modifier[@name='on']/parent::charge[@subtype='crescent']">500,750,400,400/250,750,375,375:750,750/200,600,300,300:500,800:800,600/s/s/s</xsl:when>
      <!-- explicit arrangement  -->
      <xsl:when test="modifier[@name='arrangement']"/> <!-- Do nothing (now, go through them later) -->
      <!-- Between an ordinary  -->
      <xsl:when test="parent::modifier[@name='between']/parent::ordinary">
        <xsl:variable name="ordtype"><xsl:value-of select="../../@subtype"/></xsl:variable>
        <xsl:variable name="ordsubtype"><xsl:value-of select="../../@subtype"/></xsl:variable>
        <xsl:choose>
          <!-- Test order is important - check specific subtypes before generic type -->
          <xsl:when test="$ordsubtype='chevron-couched'">n</xsl:when>
          <xsl:when test="$ordsubtype='chevron-throughout'">n</xsl:when>
          <xsl:when test="starts-with($ordsubtype,'chevronel')">x/x/200,200,180,180:500,900,240,240:800,200,180,180/x/x/x</xsl:when>
          <xsl:when test="starts-with($ordsubtype,'tressure')"><xsl:value-of select="php:function('calcPlace','w',string($number),string($conjoin),'300,300,400,500')" /></xsl:when>
          <xsl:when test="$ordsubtype='chevron-rompu' and $chief='false'">x/200,500,300,300:800,500,300,300/200,500,340,340:500,1050,200,200:800,500,340,340/200,500,200,240:500,140,200,160:500,1050,200,200:800,500,200,240/s/s</xsl:when>
          <xsl:when test="$ordsubtype='chevron-rompu' and $chief='true'">x/200,500,300,300:800,500,300,300/200,500,340,340:500,1050,200,200:800,500,340,340/s/s/s</xsl:when>
          <xsl:when test="$ordsubtype='saltire' and $chief='false'">x///150,500,180,180:850,500:500,150:500,850/x/x</xsl:when>
          <xsl:when test="$ordsubtype='saltire' and $chief='true'">x///150,700,180,180:850,700:500,380,140,140:500,1050,180,180/x/x</xsl:when>
          <xsl:when test="$ordtype='chevron' and $chief='false'">x/500,140,300,180:500,850,300,300/200,200,240,240:500,850,300,300:800,200,240,240/200,240,200,240:500,140,200,160:500,850,300,300:800,240,200,240/200,240,200,240:500,140,200,160:400,900,160,200:600,900:800,240,200,240/200,240,200,240:500,140,200,160:400,950,160,200:500,720:600,950:800,240,200,240</xsl:when>
          <xsl:when test="$ordtype='chevron' and $chief='true'">x/x/180,480,180,180:500,950,280,280:820,480,180,180/s/s</xsl:when>
          <xsl:when test="$ordtype='bend' and $chief='false'">x/750,250,250,250:250,750/750,250,250,250:200,700,200,200:400,900/200,650,200,200:400,850:600,150:800,350//600,200,140,140:800,200:800,400:200,600:400,800:200,800</xsl:when>
          <xsl:when test="$ordtype='bend' and $chief='true'">x/750,550,250,250:250,950,180,180/250,950,180,180:600,450,200,200:800,650/150,850,180,180:350,1050:600,450,200,200:800,650/600,450,140,140:800,450:800,650:200,900:350,1050:150,1050/s</xsl:when>
          <xsl:when test="$ordtype='cross' and $chief='false'">x/175,750,180,300:825,750/x/175,200,180,160:825,200:175,840:825:840/s/s</xsl:when>
          <xsl:when test="$ordtype='cross' and $chief='true'">x/200,450,180,160:800,450/x/200,450,180,160:800,450:200,940:800:840/s/s</xsl:when>
          <xsl:when test="$ordtype='cross' and $chief='false'">x/175,750,180,300:825,750/x/175,200,180,160:825,200:175,840:825:840/s/s</xsl:when>
          <xsl:when test="$ordtype='cross' and $chief='true'">x/200,450,180,160:800,450/x/200,450,180,160:800,450:200,940:800:840/s/s</xsl:when>
          <xsl:when test="$ordtype='cross' and $chief='false'">x/175,750,180,300:825,750/x/175,200,180,160:825,200:175,840:825:840/s/s</xsl:when>
          <xsl:when test="$ordtype='cross' and $chief='true'">x/200,450,180,160:800,450/x/200,450,180,160:800,450:200,940:800:840/s/s</xsl:when>
          <xsl:when test="$ordsubtype='fillet-cross' and $chief='false'">x/250,750,180,180:750,750/x/250,250,180,180:750,250:250,750:750,750/x/x</xsl:when>
          <xsl:when test="$ordsubtype='fillet-cross' and $chief='true'">x/250,500,200,200:750,500/x/250,500,200,200:750,500:250,900:750,900/x/x</xsl:when>
          <xsl:when test="$ordsubtype='cross-formy' and $chief='false'">x/250,750,180,180:750,750/x/250,250,180,180:750,250:250,750:750,750/x/x</xsl:when>
          <xsl:when test="$ordsubtype='cross-formy' and $chief='true'">x/250,950,180,180:750,950/x/250,450,180,180:750,450:250,950:750,950/x/x</xsl:when>
          <xsl:when test="$ordsubtype='pile' and $chief='false'">x/150,700,180,180:850,700/x/130,600,160,160:870,600:200,840:800,840/x/x</xsl:when>
          <xsl:when test="$ordsubtype='pile' and $chief='true'">x/150,900,180,180:850,900/x/130,800,160,160:870,800:200,1040:800,1040/x/x</xsl:when>
          <xsl:when test="$ordtype='cross2' and $chief='false'">x/175,750,180,300:825,750/x/175,620,180,160:825,620:175,840:825:840/x/x</xsl:when>
          <xsl:when test="$ordtype='cross2' and $chief='true'">x/175,850,180,300:825,850/x/175,720,180,160:825,720:175,940:825:840/x/x</xsl:when>
          <xsl:when test="($ordsubtype='orle' or $ordsubtype='double-tressure') and $chief='false'"><xsl:value-of select="php:function('calcPlace','w',string($number),string($conjoin),'250,250,500,600')" /></xsl:when>
          <xsl:when test="($ordsubtype='orle' or $ordsubtype='double-tressure') and $chief='true'"><xsl:value-of select="php:function('calcPlace','w',string($number),string($conjoin),'250,550,500,300')" /></xsl:when>
          <xsl:when test="$ordtype='pale'">x/175,550,300,800:825,550/x/175,383.33,300,350:175,716.67:825,383.33:825,716.67/x/175,300,250,200:175,550:175,800:825,300:825,550:825,800</xsl:when>
          <xsl:when test="$ordtype='fess'">x/500,150,400,180:500,850,400,300/333,150,200,200:666,150:500,850,400,300/333.33,150,300,180:667.67,150:333.33,850,300,300:667.66,850/250,150,200,180:500,150:750,150:333.33,850,300,300:667.66,850/250,150,200,180:500,150:750,150:250,850,200,300:500,850:750,850</xsl:when>
          <xsl:when test="($ordsubtype='pall' or $ordsubtype='shakefork') and $chief='false'">x/220,760,240,400:780,760/220,760,240,400:500,150,180,180:780,760,240,400/220,600,200,180:780,600:220,840:780,840/220,600,200,180:780,600:500,150,180,180:220,840,200,180:780,840/x</xsl:when>
          <xsl:when test="($ordsubtype='pall' or $ordsubtype='shakefork') and $chief='true'">x/220,1060,200,300:780,1060/220,1060,200,300:500,450,180,180:780,1060,200,300/220,900,200,160:780,900:220,840:780,1120/220,900,200,180:780,900:500,350,180,180:220,1120,200,160:780,1120/x</xsl:when>
          <xsl:when test="$ordsubtype='flaunch' or $ordsubtype='square-flaunch'"><xsl:value-of select="php:function('calcPlace','n',string($number),string($conjoin),'300,300,400,600')" /></xsl:when>
          <xsl:otherwise>n</xsl:otherwise>
        </xsl:choose>
      </xsl:when>
      <!-- explicit rows -->
      <xsl:when test="modifier[@name='rows']">
        <xsl:variable name="rows"><xsl:value-of select="modifier[@name='rows']/@param"/></xsl:variable>
        <xsl:value-of select="php:function('calcPlace','r',$rows,string($conjoin),$boundingBox)" />
      </xsl:when>
      <!-- base on underlying division -->
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-bend'] and @number='2' and $chief='false'">x/300,700,350,350:700,300/x/x/x/x</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-bend-sinister'] and @number='2' and $chief='false'">x/300,300,350,350:700,700/x/x/x/x</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-bend'] and @number='2' and $chief='true'">x/300,900,250,250:600,600/x/x/x/x</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-bend-sinister'] and @number='2' and $chief='true'">x/300,600,350,350:700,1000/x/x/x/x</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='quarterly'] and @number='4' and $chief='false'">x/x/x/250,250,300,300:750,250:250,750:750,750/x/x/</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='quarterly'] and @number='4' and $chief='true'">x/x/x/250,450,260,260:750,450:250,850:750,850/x/x/</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='gyronny' and modifier[@name='ofnum'][@param='8']] and (@number='8' or @number='4') and $chief='false'">x/x/x/200,500,300,300:500,200:800,500:500,800/x/x/x/200,400,160,160:400,200:600,200:800,400:800,600:600,800:400,800:200,600</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='gyronny' and modifier[@name='ofnum'][@param='8']] and (@number='8' or @number='4') and $chief='true'">x/x/x/200,700,250,250:500,400:800,700:500,1000/x/x/x/200,600,150,150:400,400:600,400:800,600:800,800:600,1000:400,1000:200,800</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='gyronny' and modifier[@name='ofnum'][@param='6']] and (@number='6' or @number='3') and $chief='false'">x/200,500,300,600:800,500/x/x/x/350,200,200,200:650,200:150,500:850,500:350,800:650,800</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='gyronny' and modifier[@name='ofnum'][@param='6']] and (@number='6' or @number='3') and $chief='true'">x/200,800,300,400:800,800/x/x/x/350,450,180,180:650,450:150,700:850,700:350,950:650,950</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-chevron'] and @number='3' and $chief='false'">x/x/250,200,240,240:500,750,300,300:750,200,240,240</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-chevron'] and @number='3' and $chief='true'">x/x/250,500,220,220:500,950,300,300:750,500,220,220</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-pall'] and @number='3' and $chief='false'">x/x/250,700,300,300:500,200,300,300:750,700,300,300:/x/x/x/</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-pall'] and @number='3' and $chief='true'">x/x/250,850,260,260:500,500:750,850:/x/x/x/</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-pall'] and @number='3' and $chief='false'">x/x/250,700,300,300:500,200,300,300:750,700,300,300:/x/x/x/</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-pall'] and @number='3' and $chief='true'">x/x/250,850,260,260:500,500:750,850:/x/x/x/</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-pall'] and @number='3' and $chief='false'">x/x/250,700,300,300:500,200,300,300:750,700,300,300:/x/x/x/</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-pall'] and @number='3' and $chief='true'">x/x/250,850,260,260:500,500:750,850:/x/x/x/</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-pall-reversed'] and @number='3' and $chief='false'">x/x/250,300,300,300:500,900:750,300/x/x/x/</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-pall-reversed'] and @number='3' and $chief='true'">x/x/250,500,260,260:500,950:750,500/x/x/x/</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-saltire'] and @number='3' and $chief='false'">x/200,500,240,240:800,500/200,500,240,240:500,850,300,300:800,500,240,240/200,500,240,240:500,850,300,300:800,500,240,240:500,200,240,240/x/x</xsl:when>
      <xsl:when test="parent::ord_chgs/parent::plain/tincture/division[@subtype='per-saltire'] and @number&gt;='2' and @number&lt;='4' and $chief='true'">x/200,700,220,220:800,700/200,700,220,220:500,950,260,260:800,700,220,220/200,700,220,220:500,950,260,260:800,700,220,220:500,450,220,220/x/x</xsl:when>
      <!-- default, arrange in default rows -->
      <xsl:otherwise>
          <xsl:choose>
            <xsl:when test="modifier[@name='position'][@param='indexchief' or @param='insinchief' or @param='insinside' or @param='indexside']">
              <xsl:value-of select="php:function('calcPlace','n',string($number),string($conjoin),$boundingBox)" />
            </xsl:when>
            <xsl:otherwise>
              <xsl:value-of select="php:function('calcPlace','w',string($number),string($conjoin),$boundingBox)" />
            </xsl:otherwise>
          </xsl:choose> 
      </xsl:otherwise>
    </xsl:choose>
  </xsl:variable>
  <!-- Add the placement modifier -->
  <xsl:if test="$placement!=''">
    <xsl:element name="modifier">
      <xsl:attribute name="name">placement</xsl:attribute>
      <xsl:attribute name="param">
        <xsl:value-of select="$placement" />
      </xsl:attribute>            
    </xsl:element>
  </xsl:if>
      <!-- ========================= -->
      <!-- Specific Arrangements     -->
      <!-- ========================= -->
  <xsl:for-each select="modifier[@name='arrangement']">
    <xsl:element name="modifier">
      <xsl:attribute name="name">placement</xsl:attribute>
      <xsl:attribute name="param" >           
        <xsl:choose>
          <xsl:when test="@param='inbend' and $chief='false'">500,500,400,800,-45/333.33,333.33,180,180,45:666.67,666.67/250,250,200,200,45:500,500:750,750/200,200,200,200,45:400,400:600,600:800,800/166.67,166.67,160,160,45:333.33,333.33:500,500:666.67,666.67:833.33,833.33/142.86,142.86,140,140,45:285.71,285.71:428.57,428.57:571.43,571.43:714.29,714.29:857.14,857.14</xsl:when>
          <xsl:when test="@param='inbend' and $chief='true'">500,800,350,700,-45/333.33,633.33,180,180,45:666.67,966.67/200,500,180,180,45:400,700:600,900/166.67,466.67,180,180,45:333.33,633.33:500,800:666.67,966.67/142.86,442.86,180,180,45:285.71,585.71:428.57,728.57:571.43,871.43:714.29,1014.29/s</xsl:when>
          <xsl:when test="@param='inpale' and $chief='false'"><xsl:value-of select="php:function('calcPlace','v',string($number),string($conjoin),'350,100,300,1000')" /></xsl:when>
          <xsl:when test="@param='inpale' and $chief='true'"><xsl:value-of select="php:function('calcPlace','v',string($number),string($conjoin),'350,350,300,750')" /></xsl:when>
          <xsl:when test="@param='inchief'"><xsl:value-of select="php:function('calcPlace','h',string($number),string($conjoin),'100,25,800,250')" /></xsl:when>
          <xsl:when test="@param='inchiefthrough'"><xsl:value-of select="php:function('calcPlace','h',string($number),string($conjoin),'0,25,1000,250')" /></xsl:when>
          <xsl:when test="@param='inbase'">500,950,500,240/333.33,950,300,200:666.67,950/333.33,900,160,160:666.67,900:500,1050/x/x/x</xsl:when>
          <xsl:when test="@param='inflank'">x/100,500,150,800:900,500/x/100,333,150,320:900,333:100,666:900:666/x/100,250,150,250:900,250:100,500:900,500:100,750:900,750/x</xsl:when>
          <xsl:when test="@param='inpall' and $chief='false'">x/x/250,250,180,400,-45:750,250,,,45:500,750,,,0/s/s/s'</xsl:when>
          <xsl:when test="@param='inpall' and $chief='true'">x/x/250,550,180,400,-45:750,550,,,45:500,950,,,0/s/s/s</xsl:when>
          <xsl:when test="@param='inpalethrough' and $chief='false'"><xsl:value-of select="php:function('calcPlace','v',string($number),string($conjoin),'350,0,300,1200')" /></xsl:when>
          <xsl:when test="@param='inpalethrough' and $chief='true'"><xsl:value-of select="php:function('calcPlace','v',string($number),string($conjoin),'350,300,300,900')" /></xsl:when>
          <xsl:when test="@param='infess'"><xsl:value-of select="php:function('calcPlace','h',string($number),string($conjoin),'100,300,800,300')" /></xsl:when>
          <xsl:when test="@param='infessthrough'"><xsl:value-of select="php:function('calcPlace','h',string($number),string($conjoin),'0,300,1000,300')" /></xsl:when>
          <xsl:when test="@param='inbendsin'">500,500,200,200,-45/333.33,666.67,200,200,-45:666.67,333.33/250,750,200,200,-45:500,500:750,250/200,800,200,200,-45:400,600:600,400:800,200/166.67,833.33,160,160,-45:333.33,666.67:500,500:666.67,333.33:833.33,166.67/142.86,857.14,140,140,-45:285.71,714.29:428.57,571.43:571.43,428.57:714.29,285.71:857.14,142.86</xsl:when>
          <xsl:when test="@param='inchevron' and $chief='false'">x/250,625,160,160,45:750,625,,,-45/250,625,150,150,45:500,400,,,0:750,625,,,-45/200,675,140,140,45:400,475:600,475,,,-45:800,675/200,675,140,140,45:350,525:500,400,,,0:650,525,,,-45:800,675/150,725,120,120,45:250,625:350,525:650,525,,,-45:750,625:850,725</xsl:when>
          <xsl:when test="@param='inchevron' and $chief='true'">x/250,725,160,160,45:750,725,,,-45/250,725,150,150,45:500,500,,,0:750,725,,,-45/200,775,140,140,45:400,575:600,575,,,-45:800,775/200,775,140,140,45:350,625:500,500,,,0:650,625,,,-45:800,775/150,825,120,120,45:250,725:350,625:650,625,,,-45:750,725:850,825</xsl:when>
          <xsl:when test="@param='incross'">x/x/x/500,200,200,200:250,500:750,500:500,800/500,200,200,200:250,500:500,500:750,500:500,800/x</xsl:when>
          <xsl:when test="@param='insaltire'">x/x/x/200,200,200,200,-45:800,200,,,45:200,800,,,45:800,800,,,-45/200,200,200,200,-45:800,200,,,45:500,500,,,0:200,800,,,45:800,800,,,-45/x</xsl:when>
          <xsl:when test="@param='inpile'">x/x/250,250,300,300:500,600:750,250/x/x/250,200,200,200:500:750:333.33,500:666.67:500,800</xsl:when>
          <xsl:when test="@param='inorle'">///////////500,100,100,100:100,650:900,650:500,1050:100,100:900,100:100,400:900,400:200,900:800,900:300,100:700,100</xsl:when>
          <xsl:when test="@param='counter-passant'">x/500,333.33,800,350:500,666.67,,,,,1/500,250,800,200:500,500,,,,,1:500,750,,,,,0/500,200,600,160:500,400,,,,,1:500,600,,,,,0:500,800,,,,,1/500,166.67,160,160:500,333.33,,,,,1:500,500,,,,,0:500,666.67,,,,,1:500,833.33,,,,,0/500,142.86,500,140:500,285.71,,,,,1:500,428.57,,,,,0:500,571.43,,,,,1:500,714.29,,,,,0:500,857.14,,,,,1</xsl:when>
          <xsl:when test="@param='pilewise' and $chief='false'">x/300,550,200,600,-30,1:700,,,,30,1/250,600,180,550,-30,1:500,550,,,0,1:750,600,,,30,1/200,650,150,500,-38,1:400,600,,,-16,1:600,,,,16,1:800,650,,,38,1/x/x</xsl:when>
          <xsl:when test="@param='pilewise' and $chief='true'">x/300,200,200,600,-30,1:700,,,,30,1/250,750,180,550,-30,1:500,700,,,0,1:750,750,,,30,1/200,850,150,500,-38,1:400,750,,,-16,1:600,,,,16,1:800,800,,,38,1/x/x</xsl:when>
          <xsl:otherwise>i</xsl:otherwise>
        </xsl:choose>
      </xsl:attribute>
    </xsl:element>
  </xsl:for-each>
  <!-- ========================= -->
  <!-- Set Locations             -->
  <!-- ========================= -->
  <xsl:for-each select="modifier[@name='position']">
    <xsl:element name="modifier">
      <xsl:attribute name="name">location</xsl:attribute>
      <xsl:attribute name="param" >           
      <xsl:choose>
        <xsl:when test="@param='indexchief'">50,50,400,400</xsl:when>
        <xsl:when test="@param='insinchief'">550,50,400,400</xsl:when>
        <xsl:when test="@param='inmidchief'">250,50,400,400</xsl:when>
        <xsl:when test="@param='indexbase'">150,750,350,400</xsl:when>
        <xsl:when test="@param='insinbase'">500,750,350,400</xsl:when>
        <xsl:when test="@param='inmidbase'">300,750,400,400</xsl:when>
        <xsl:when test="@param='inhonpoint'">300,150,400,400</xsl:when>
        <xsl:when test="@param='infesspoint'">250,250,500,500</xsl:when>
        <xsl:when test="@param='innombril'">300,700,400,400</xsl:when>
        <xsl:when test="@param='insinside'">50,200,400,600</xsl:when>
        <xsl:when test="@param='indexside'">550,200,400,400</xsl:when>
        <xsl:when test="@param='inquarter1'">50,50,400,400</xsl:when>
        <xsl:when test="@param='inquarter2'">550,50,400,400</xsl:when>
        <xsl:when test="@param='inquarter3'">50,550,400,400</xsl:when>
        <xsl:when test="@param='inquarter4'">550,550,400,400</xsl:when>
        <xsl:otherwise>default</xsl:otherwise>
      </xsl:choose>
      </xsl:attribute>
    </xsl:element>
    <!-- In case of multiple locations, place "count" charges in this location -->
    <xsl:element name="modifier">
      <xsl:attribute name="name">count</xsl:attribute>
      <xsl:attribute name="param">
        <xsl:choose>
          <xsl:when test="@param='inflank'">2</xsl:when>
          <xsl:otherwise>1</xsl:otherwise>
        </xsl:choose>
      </xsl:attribute>
    </xsl:element>
  </xsl:for-each>
  </charge>
  </xsl:template>
  <!-- ========================= -->
  <!-- Finding parameters        -->
  <!-- ========================= -->
  <!-- Impaled and friends - set region to I1 etc. -->
  <xsl:template match="impaled/*|dimidiated/*|quartered/*">
    <xsl:variable name="prefix"><xsl:value-of select="substring(name(..),1,1)"/></xsl:variable>
    <xsl:copy>
      <xsl:apply-templates select="*|@*">
        <xsl:with-param name="region"><xsl:value-of select="concat($prefix,position())"/></xsl:with-param>
      </xsl:apply-templates>
    </xsl:copy>
  </xsl:template>
  <!-- ========================= -->
  <!-- The default match         -->
  <!-- ========================= -->
  <xsl:template match="@*|*" priority="-2">
    <xsl:param name="region"/>
    <xsl:copy>
      <xsl:apply-templates select="*|@*">
        <xsl:with-param name="region" select="$region"/>
      </xsl:apply-templates>
    </xsl:copy>
  </xsl:template>
</xsl:stylesheet>
