# Remove Language and Script Support
Espeak-ng supports 100+ languages. But incase you are not a multilingual and is very reserved about the space utilized by espeak-ng it would be worthwhile to remove unwanted language support completely.

## Objectives
Language contaons two parts. Language data and language script. So the objectives are:
- Support Language data 
- Support script support
  
## Procedure
## Remove Language Data
Very simple procedure. Espeak-ng stores language data by default in the directory `/usr/share/local/espeak-ng-data`. If it is not present there try `/usr/share/espeak-ng-data`.
1. Goto the folder
```
cd /usr/share/local/espeak-ng-data
ls
```
2. It will show the data files of all supported languages:
```
af_dict   eo_dict   ia_dict      lv_dict            phonindex  sw_dict
am_dict   es_dict   id_dict      mbrola_ph          phontab    ta_dict
an_dict   et_dict   intonations  mi_dict            piqd_dict  te_dict
ar_dict   eu_dict   io_dict      mk_dict            pl_dict    th_dict
as_dict   fa_dict   is_dict      ml_dict            pt_dict    tk_dict
az_dict   fi_dict   it_dict      mr_dict            py_dict    tn_dict
ba_dict   fr_dict   ja_dict      ms_dict            qdb_dict   tr_dict
bg_dict   ga_dict   jbo_dict     mt_dict            quc_dict   tt_dict
bn_dict   gd_dict   ka_dict      my_dict            qu_dict    ug_dict
bpy_dict  gn_dict   kk_dict      nci_dict           ro_dict    uk_dict
bs_dict   grc_dict  kl_dict      ne_dict            ru_dict    ur_dict
ca_dict   gu_dict   kn_dict      nl_dict            sd_dict    uz_dict
chr_dict  hak_dict  ko_dict      no_dict            shn_dict   vi_dict
cs_dict   haw_dict  kok_dict     nog_dict           si_dict    voices
cv_dict   he_dict   ku_dict      om_dict            sk_dict    zh_dict
cy_dict   hi_dict   ky_dict      or_dict            sl_dict    zhy_dict
da_dict   hr_dict   la_dict      pa_dict            smj_dict
de_dict   ht_dict   lang         pap_dict           sq_dict
el_dict   hu_dict   lfn_dict     phondata           sr_dict
en_dict   hy_dict   lt_dict      phondata-manifest  sv_dict
```
Remove unwanted languages using **rm** command.  
`sudo rm af_dict`  
The above command will remove african support. Similarly remove every unwanted file.

## Remove Script Support
Script support should be removed from **`src/libespeak-ng/tr_languages.c`**. Go throught the code and comment all unwanted language code.  
**tr_languages.c** file in this repository is modifeid in such a way that it only support English (Latin script) and south Indic (Malayalam, Tamil, Telugu etc) scripts.

### Space saved after editing tr_languages.c

All Languages*

|file                      | size (bytes) |
---------------------  |  ----------------
|libespeak-ng.a   |2,584,008     |
|libespeak-ng.so |1,557,248      |


English Only

|file                      | size (bytes) |
---------------------  |  ----------------
|libespeak-ng.a   |2,420,760     |
|libespeak-ng.so |1,448,576      |

English + South Indian Languages

|file                      | size (bytes) |
---------------------  |  ----------------
|libespeak-ng.a   |2,427,696     |
|libespeak-ng.so |1,456,096      |
