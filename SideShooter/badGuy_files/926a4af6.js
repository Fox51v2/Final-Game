var MalwareWarning;(function(n){function l(){if(!r||!e||!o||!s){r=null;return}sj_be(e,i,t);sj_be(o,i,t);sj_be(s,i,h);sj_be(_w,"unload",f);sj_evt.bind("ajax.unload",f)}function f(){sj_ue(e,i,t);sj_ue(o,i,t);sj_ue(s,i,h);sj_ue(_w,"unload",f);sj_evt.unbind("ajax.unload",f)}function t(){r&&c.sdt(r,4);sj_ue(_w,i,t);sj_ue(_w,"scroll",t);u=null}function h(){u&&_w.open(u,"_blank");t()}function a(n){u=n;r?(c.sdt(r,1),sj_be(_w,i,t),sj_be(_w,"scroll",t)):h()}var i="click",c=pMMUtils,r=_ge("mws_dlg"),e=_ge("mws_x"),o=_ge("mws_n"),s=_ge("mws_y"),u;l();n.show=a})(MalwareWarning||(MalwareWarning={}))