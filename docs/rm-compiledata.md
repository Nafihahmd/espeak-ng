# Remove Language Compile Data
Language files are generally compiled at the time espeak-ng is build. This is a one time process. Once the language files are once build this code (inside `compiledata.c` and `compiledict.c`) is useless. So we are going to remove this compile code and instead provide compiled language data to espeak-ng beforehand of buillding.

## Objectives
- remove compiledata.c
- remove compiledict.c

## Procedure
- As of now code with compile code removed is not merged with master branch and is kept separately in the branch `rm-compile-data`. Clone the branch:
```
git clone -b rm-compile-data --single-branch https://github.com/Nafihahmd/espeak-ng.git
```
- Go to the cloned folder and unzip the **espeak-ng-data.zip** archive
```
cd espeak-ng
unzip espeak-ng-data.zip
```
That's it, you are done. Now follow the normal build process defined [here](building.md).  

## Result

**Before**:

|file                      | size (bytes) | size after stripping** |
---------------------  |  ---------------- | -----------------------
|libespeak-ng.a   |2,584,008     |454,842  |
|libespeak-ng.so |1,557,248      | 498,486 |

**After**:

|file                      | size (bytes) | size after stripping** |
---------------------  |  ---------------- | -----------------------
|libespeak-ng.a   |2,107,022     |392,106  |
|libespeak-ng.so |1,264,176      | 427,736 |

