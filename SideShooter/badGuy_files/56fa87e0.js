var ImageDetailInsightsViewer;(function(){function k(){typeof r!="undefined"&&r!=null&&(t=ImageInsightsViewerUtils.Create(r,a,v,p,n,y,r.firstChild?2:0),i=w.qsv("q",!0),i&&i.toLowerCase().indexOf("imgurl:")===0&&(i=""),sj_be(_w,"unload",h),sj_evt.bind("ajax.unload",h),sj_evt.bind(4,o,!0),sj_evt.bind(0,s,!0),u&&sj_be(u,"click",l))}function o(i){var r=i[1],u;(n==null||n.index!=r.index)&&((u=n==null,n=r,t.UpdateCurrentInfo(n),u&&t.getLoadState()==2)||(t.clearInsightsContent(),c()&&f()))}function f(){var f,r,u,e;if(n!=null&&(f=n.index,r=n.resultData,r!=null)){if(!r.issbi&&!b.test(r.mid)){t.onNoInsightsData(f);return}u=typeof r.brq!="undefined"&&r.brq?r.brq:"";e={mid:r.mid,ccid:r.ccid,vw:typeof r.vw=="undefined"?"":r.vw,simid:r.docid,thid:r.thId,thh:r.height,thw:r.width,q:u,qpvt:i,mst:r.mst,mscr:r.mscr,spurl:r.pageUrl,imgurl:r.issbi?r.imgUrl:null,brq:u?u:null,bcid:r.issbi&&typeof r.bcid!="undefined"?r.bcid:null};t.FetchInsights(e,f)}}function s(n){e=n[1];c()&&t.getLoadState()===0&&(t.clearInsightsContent(),f())}function h(){sj_evt.unbind(1,o);sj_evt.unbind(0,s);u&&sj_ue(u,"click",l)}function c(){return e==1}function l(){t.clearInsightsContent();f()}var e=0,r=_ge("insights"),a=_ge("insightsError"),v=_ge("insightsErrorExpected"),u=_ge("retry"),y=_ge("tryViewPage"),p="loading",w=pMMUtils,i="",n=null,t,b=new RegExp("^[0-9a-fA-F]{40}$");k()})(ImageDetailInsightsViewer||(ImageDetailInsightsViewer={}))