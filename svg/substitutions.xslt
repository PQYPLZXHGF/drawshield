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
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="xml" omit-xml-declaration="no" indent="no" />
<xsl:strip-space elements="*"/>
  <!-- discard all text nodes -->
  <xsl:template match="text()"/>
  <!-- ========================= -->
  <!-- some simple substitutions -->
  <!-- ========================= -->
  <!-- inbar -->
  <xsl:template match="modifier[@name='arrangement' and @param='inbar']" >
    <modifier name="arrangement" param="inpale" />
    <modifier name="orientation" param="fesswise" />
  </xsl:template>
  <!-- We implement concentric annulets as a single charge of "number" rings -->
  <xsl:template match="charge[@subtype='annulet']">
    <charge type="annulet" subtype="annulet" number="1">
      <xsl:apply-templates select="node()[not(self::modifier/@name='concentric')]" />
      <modifier name="concentric" param="{@number}"/>
    </charge>
  </xsl:template>
  <!-- fountain -->
  <xsl:template match="charge[@subtype='fountain']" >
    <charge type="geometric" subtype="roundel" number="{@number}">
      <tincture>
        <division type="bar" subtype="barry" linetype="wavy">
          <tincture><colour name="azure" /></tincture>
          <tincture><colour name="argent" /></tincture>
          <modifier name="ofnum" param="6"/>
        </division>
      </tincture>
      <xsl:apply-templates select="node()[not(self::tincture)]" />
    </charge>
  </xsl:template>
  <!-- Named Roundels -->
  <xsl:template match="charge[@type='named-roundel']">
    <charge type="geometric" subtype="roundel" number="{@number}">
      <tincture>
        <colour>
          <xsl:attribute name="name">
            <xsl:choose>
              <xsl:when test="@subtype='bezant'">or</xsl:when>
              <xsl:when test="@subtype='plate'">argent</xsl:when>
              <xsl:when test="@subtype='hurt'">azure</xsl:when>
              <xsl:when test="@subtype='torteau'">gules</xsl:when>
              <xsl:when test="@subtype='pellet'">sable</xsl:when>
              <xsl:when test="@subtype='pomme'">vert</xsl:when>
              <xsl:when test="@subtype='golpe'">purpure</xsl:when>
              <xsl:when test="@subtype='orange'">tenne</xsl:when>
              <xsl:when test="@subtype='guze'">sanguine</xsl:when>
            </xsl:choose>
          </xsl:attribute>
        </colour>
      </tincture>
      <xsl:apply-templates select="node()[not(self::tincture)]" />
    </charge> 
  </xsl:template>
  <!-- on ordinary another of the first => voided -->
  <xsl:template match="ordinary/modifier[@name='on' and child::ordinary/@subtype='another']">
  	<modifier name="voided">
  	  <xsl:copy-of select="ordinary/*"/>
  	</modifier>
  </xsl:template>
  <!-- the default match -->
  <xsl:template match="@*|*" priority="-2" >
    <xsl:copy>
      <xsl:apply-templates select="*|@*" />
    </xsl:copy>
  </xsl:template>
</xsl:stylesheet>

