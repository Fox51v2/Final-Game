(function(){var n=function(){function yt(){r=_ge("can_fav");rt=_ge("can_fav_icon");ut=_ge("fav_icon_container");s.bind(ut,"mouseenter",bt);s.bind(rt,"click",wt)}function pt(){y=n.gfbc("text",v);y&&(nt=n.ga(y,"url"),nt&&s.bind(y,"click",function(n){_w.location.href=nt;sj_pd(n);sj_sp(n);n.stopPropagation()}))}function wt(n){et(n,c())}function bt(){r.title="";n.ha(r,"tooltip")&&(g=n.ga(r,"tooltip"),g&&ft&&(at.innerHTML=g),sj_evt.fire(9,ft))}function et(n,t){var r=sj_et(n);if(sj_pd(n),sj_sp(n),n.stopPropagation(),!t||!t.df){if(favresources.favnsi===!0){if(!o&&kt()){i=r;tt(t,r);ot(i);return}}else if(!o){u=t;i=r;ot(i);return}tt(t,r)}}function kt(){return typeof ImageFavorites!="undefined"?ImageFavorites.iffbc():!0}function tt(n,t){typeof ImageFavorites!="undefined"&&n&&n.pageUrl&&n.imgUrl&&typeof t!="undefined"&&ImageFavorites.hic(n,t,f)}function ot(i){var f=b(i),e=_ge("favba"),u,o,s,r;e&&e.firstChild&&f&&(l||(u=e.firstChild.cloneNode(!0),n.sdt(u,3),f.appendChild(u),n.ac(f,p),o=st(),o&&n.ac(o,p),gt(),lt(),favresources.favnsi===!0?(r=_ge("signInUpsellLink"),r&&(r.onclick=function(n){ht(n)},r.onmousedown=r.onmouseup=function(n){n.stopPropagation()}),s=_ge("signInLaterText"),s&&(s.onclick=function(){t(!0)}),sj_evt.fire(DetailPageEvent[8],1)):(r=u.firstChild,r&&(r.onclick=function(n){ht(n)},r.onmousedown=r.onmouseup=function(n){n.stopPropagation()})),l=!0,sj_evt.fire(9,u),ni(),FavLog.l(1,2)))}function dt(){var n=b(i);n&&a&&(n.title=a,a="")}function gt(){var n=b(i);n&&(a=n.title,n.title="")}function t(t){var r,u;t===void 0&&(t=!0);l&&(r=b(i),r&&(dt(),r.removeChild(r.lastChild),n.rc(r,p),u=st(),u&&n.rc(u,p),l=!1,ti(),t&&FavLog.l(1,3),favresources.favnsi===!0&&sj_evt.fire(DetailPageEvent[8],0)))}function st(){var n=vt.getCurrImg();return n?n.parentNode:null}function b(t){return d?t===n.gfbc("faicon",r)?r:v:v}function ni(){sj_be(_w,"click",t);sj_be(_w,"scroll",t);sj_be(_w,"unload",t);sj_evt.bind("ajax.unload",t)}function ti(){sj_ue(_w,"click",t);sj_ue(_w,"scroll",t);sj_ue(_w,"unload",t);sj_evt.unbind("ajax.unload",t)}function ht(n){typeof Identity!="undefined"&&(FavLog.l(1,1),Identity.popupAuthenticate("WindowsLiveId"),t(!1));n&&n.stopPropagation()}function ii(){typeof Identity!="undefined"&&Identity.wlProfile()&&typeof LoadFavLogic!="undefined"&&(LoadFavLogic(),MMMessenger.Post(_w.parent,"Favorite.SignIn",null),FavLog.l(3))}function ct(){var i=c(),t;i&&(t=d?r:v,t&&n.sdt(t,i.df?0:3))}function lt(){sj_evt.fire("Favorites.HideMoveToBalloon")}function ri(){if(ct(),t(!1),lt(),o||favresources.favnsi){var n=c();n&&(typeof ImageFavorites!="undefined"?it(n):(k=!0,u=n))}}function it(n){var t=n.isFav;ImageFavorites.createInsightsStyleForButtons(f,t);ImageFavorites.changeDisplayFavoritesButton(f,n.df)}function ui(){favresources.favnsi===!0?typeof Identity!="undefined"&&Identity.wlProfile()&&(o=!0):o=!0;i&&u&&tt(u,i);k&&u&&it(u)}var n=typeof pMMUtils!="undefined"?pMMUtils:null,l=!1,u,i,a="",k=!1,o=!1,d=_ge("can_fav")?!0:!1,r,rt,ut,g="",s=SmartEvent,v=_ge("action_fav"),ft=_ge("fav_tooltip"),at=_ge("fav_text"),y,nt,p="signInOpened",vt=ImageDetailMainImage,h,f,w,c,e;if((typeof Identity!="undefined"&&Identity.wlProfile()||favresources.favnsi===!0)&&typeof LoadFavLogic!="undefined"&&LoadFavLogic(),h=DetailPageActionButton.apply(null,[null,"action_fav",et,ri]),f=[],d)for(yt(),f.push(r),w=0;w<h.instance.length;w++)f.push(h.instance[w]);else pt(),f=h.instance;c=h.getCurMeta;e=c();e&&(e.isFav||e.df)&&(typeof ImageFavorites!="undefined"?it(e):(k=!0,u=e));ct();s.bindc("wl:auth",ii);s.bindc("Favorites.Loaded",ui);_ge("signIn")||typeof LoadFavLogic=="undefined"||LoadFavLogic()},t=new n})()