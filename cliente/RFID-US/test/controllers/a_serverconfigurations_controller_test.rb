require 'test_helper'

class AServerconfigurationsControllerTest < ActionController::TestCase
  setup do
    @a_serverconfiguration = a_serverconfigurations(:one)
  end

  test "should get index" do
    get :index
    assert_response :success
    assert_not_nil assigns(:a_serverconfigurations)
  end

  test "should get new" do
    get :new
    assert_response :success
  end

  test "should create a_serverconfiguration" do
    assert_difference('AServerconfiguration.count') do
      post :create, a_serverconfiguration: { gateway: @a_serverconfiguration.gateway, ipdevice: @a_serverconfiguration.ipdevice, networkmask: @a_serverconfiguration.networkmask, refreshtime: @a_serverconfiguration.refreshtime, url_server: @a_serverconfiguration.url_server }
    end

    assert_redirected_to a_serverconfiguration_path(assigns(:a_serverconfiguration))
  end

  test "should show a_serverconfiguration" do
    get :show, id: @a_serverconfiguration
    assert_response :success
  end

  test "should get edit" do
    get :edit, id: @a_serverconfiguration
    assert_response :success
  end

  test "should update a_serverconfiguration" do
    patch :update, id: @a_serverconfiguration, a_serverconfiguration: { gateway: @a_serverconfiguration.gateway, ipdevice: @a_serverconfiguration.ipdevice, networkmask: @a_serverconfiguration.networkmask, refreshtime: @a_serverconfiguration.refreshtime, url_server: @a_serverconfiguration.url_server }
    assert_redirected_to a_serverconfiguration_path(assigns(:a_serverconfiguration))
  end

  test "should destroy a_serverconfiguration" do
    assert_difference('AServerconfiguration.count', -1) do
      delete :destroy, id: @a_serverconfiguration
    end

    assert_redirected_to a_serverconfigurations_path
  end
end
