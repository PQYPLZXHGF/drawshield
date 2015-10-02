# Introduction #

This page documents the steps to be take when a new release of
Drawshield is ready, and should be regarded as a mandatory checklist.


# Procedures #

  1. Run the "build data" process
  1. Run localhost/include/shield/regress.php & confirm results
  1. (When complete) run the "build docs" process
  1. Commit all changed files to SVN, note as "release version"
  1. Set an SVN "tag" on all files as per the release no. e.g. "2.3e"
  1. Upload all files to shield-2-3e (match release number)
  1. Rename existing folder shield to shield-2-3d (previous release)
  1. Rename shield-2-3e (release number) to shield
  1. Using drawhshield example page confirm operation and release number
  1. (If required, previous versions can be deleted)
  1. Publish release notes on blog, Title Drawshield 2.3e Release Notes
    1. New Features
    1. Bug Fixes
    1. Internal Changes
  1. Edit drawshield.php to next version number
  1. Run localhost/include/shield/regress.php?rebuild
  1. Code new version!